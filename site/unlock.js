// Password gate: decrypts content.js (AES-GCM, key from PBKDF2) and then starts app.js.
const lockScreen = document.querySelector('#lock');
const lockForm = document.querySelector('#lock-form');
const lockInput = document.querySelector('#lock-password');
const lockError = document.querySelector('#lock-error');
const STORAGE_KEY = 'calendar-password';

const snow = document.querySelector('#snow');
for (let i = 0; i < 40; i++) {
  const flake = document.createElement('span');
  flake.className = 'flake';
  flake.textContent = '❄';
  flake.style.left = Math.random() * 100 + 'vw';
  flake.style.fontSize = 0.5 + Math.random() * 1.1 + 'em';
  flake.style.animationDuration = 7 + Math.random() * 10 + 's';
  flake.style.animationDelay = -Math.random() * 17 + 's';
  snow.appendChild(flake);
}

function fromBase64(text) {
  return Uint8Array.from(atob(text), (c) => c.charCodeAt(0));
}

async function decrypt(password) {
  const box = window.CALENDAR_ENCRYPTED;
  const material = await crypto.subtle.importKey('raw', new TextEncoder().encode(password), 'PBKDF2', false, ['deriveKey']);
  const key = await crypto.subtle.deriveKey(
    { name: 'PBKDF2', salt: fromBase64(box.salt), iterations: box.iterations, hash: 'SHA-256' },
    material,
    { name: 'AES-GCM', length: 256 },
    false,
    ['decrypt'],
  );
  const plain = await crypto.subtle.decrypt({ name: 'AES-GCM', iv: fromBase64(box.iv) }, key, fromBase64(box.data));
  return JSON.parse(new TextDecoder().decode(plain));
}

function startApp() {
  lockScreen.hidden = true;
  const script = document.createElement('script');
  script.src = 'app.js';
  document.body.appendChild(script);
}

async function tryUnlock(password, remember) {
  try {
    window.CALENDAR = await decrypt(password);
  } catch {
    return false;
  }
  if (remember) sessionStorage.setItem(STORAGE_KEY, password);
  startApp();
  return true;
}

lockForm.addEventListener('submit', async (event) => {
  event.preventDefault();
  lockError.hidden = true;
  if (!(await tryUnlock(lockInput.value, true))) {
    lockError.hidden = false;
    lockInput.select();
    lockForm.classList.remove('shake');
    void lockForm.offsetWidth;
    lockForm.classList.add('shake');
  }
});

(async () => {
  if (window.CALENDAR) {
    startApp();  // unencrypted local build
    return;
  }
  const saved = sessionStorage.getItem(STORAGE_KEY);
  if (saved && (await tryUnlock(saved, false))) return;
  sessionStorage.removeItem(STORAGE_KEY);
  lockScreen.hidden = false;
  lockInput.focus();
})();
