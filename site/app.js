// Door positions over calendar.jpg, in percent of the image: [day, left, top, width, height]
const COLS = [8.1, 25.5, 43.0, 60.3, 77.7];
const ROWS = [23.0, 34.5, 46.0, 57.4, 69.0];
const DOOR_W = 14.3;
const DOOR_H = 9.3;

const DOORS = [];
for (let i = 0; i < 20; i++) {
  DOORS.push([i + 1, COLS[i % 5], ROWS[Math.floor(i / 5)], DOOR_W, DOOR_H]);
}
// Last row: 21, 22, (empty), 23, 24
DOORS.push([21, COLS[0], ROWS[4], DOOR_W, DOOR_H]);
DOORS.push([22, COLS[1], ROWS[4], DOOR_W, DOOR_H]);
DOORS.push([23, COLS[3], ROWS[4], DOOR_W, DOOR_H]);
DOORS.push([24, COLS[4], ROWS[4], DOOR_W, DOOR_H]);
// Day 25: the big board at the bottom. Day 0: the board at the top.
DOORS.push([25, 38.4, 81.2, 23.4, 14.0]);
DOORS.push([0, 40.4, 11.4, 20.8, 10.0]);
DOORS.push([0, 16.9, 15.7, 22.0, 5.7]); // "Start Here!" sign

const DECORATIONS = ['🎄', '⭐', '❄️', '🎁', '🔔', '🎅', '🦌', '✨', '🍬', '🧦', '☃️'];
const reducedMotion = window.matchMedia('(prefers-reduced-motion: reduce)').matches;

const byDay = new Map(window.CALENDAR.map((entry) => [entry.day, entry]));
const calendarView = document.querySelector('#calendar-view');
const reader = document.querySelector('#reader');
const doorsEl = document.querySelector('#doors');
const curtain = document.querySelector('#curtain');
const particles = document.querySelector('#particles');
let busy = false;

// ---------- Build the doors ----------
for (const [day, left, top, width, height] of DOORS) {
  const entry = byDay.get(day);
  if (!entry) continue;
  const door = document.createElement('button');
  door.type = 'button';
  door.className = 'door';
  door.style.left = left + '%';
  door.style.top = top + '%';
  door.style.width = width + '%';
  door.style.height = height + '%';
  door.title = day === 0 ? 'Start here' : `Day ${day}`;
  door.setAttribute('aria-label', door.title);
  door.addEventListener('click', () => openDay(day, door));
  doorsEl.appendChild(door);
}

// ---------- Animations ----------
const wait = (ms) => new Promise((resolve) => setTimeout(resolve, reducedMotion ? 0 : ms));

function burstDecorations(x, y) {
  if (reducedMotion) return;
  for (let i = 0; i < 28; i++) {
    const p = document.createElement('span');
    p.className = 'particle';
    p.textContent = DECORATIONS[Math.floor(Math.random() * DECORATIONS.length)];
    const angle = Math.random() * Math.PI * 2;
    const distance = 120 + Math.random() * 260;
    p.style.left = x + 'px';
    p.style.top = y + 'px';
    p.style.fontSize = 18 + Math.random() * 22 + 'px';
    p.style.setProperty('--dx', Math.cos(angle) * distance + 'px');
    p.style.setProperty('--dy', Math.sin(angle) * distance + 'px');
    p.style.setProperty('--rot', (Math.random() * 720 - 360) + 'deg');
    p.style.animationDelay = Math.random() * 0.15 + 's';
    particles.appendChild(p);
    p.addEventListener('animationend', () => p.remove());
  }
}

async function curtainTransition(x, y, swap) {
  curtain.style.setProperty('--x', x + 'px');
  curtain.style.setProperty('--y', y + 'px');
  curtain.className = 'closing';
  await wait(600);
  swap();
  window.scrollTo(0, 0);
  curtain.className = 'opening';
  await wait(600);
  curtain.className = '';
}

async function openDay(day, door) {
  if (busy) return;
  busy = true;
  const rect = door.getBoundingClientRect();
  const x = rect.left + rect.width / 2;
  const y = rect.top + rect.height / 2;

  burstDecorations(x, y);
  door.classList.add('opening');
  await wait(650);
  await curtainTransition(x, y, () => {
    door.classList.remove('opening');
    history.pushState(null, '', '#day-' + String(day).padStart(2, '0'));
    render();
  });
  busy = false;
}

async function navigate(hash) {
  if (busy) return;
  busy = true;
  await curtainTransition(window.innerWidth / 2, 40, () => {
    history.pushState(null, '', hash || location.pathname);
    render();
  });
  busy = false;
}

// ---------- Reader ----------
function currentDay() {
  const match = location.hash.match(/^#day-(\d+)$/);
  return match && byDay.has(Number(match[1])) ? Number(match[1]) : null;
}

function render() {
  const day = currentDay();
  if (day === null) {
    reader.hidden = true;
    calendarView.hidden = false;
    document.title = 'Arduino Christmas Calendar';
    return;
  }

  const entry = byDay.get(day);
  document.querySelector('#badge').textContent = day === 0 ? '🎄' : day;
  document.querySelector('#title').textContent = day === 0 ? entry.title : `Day ${day} - ${entry.title}`;
  document.querySelector('#content').innerHTML = marked.parse(entry.markdown);

  const download = document.querySelector('#download');
  download.hidden = !entry.zip;
  if (entry.zip) download.href = entry.zip;

  document.querySelector('#prev').disabled = !byDay.has(day - 1);
  document.querySelector('#next').disabled = !byDay.has(day + 1);
  document.title = `${day === 0 ? 'Introduction' : 'Day ' + day} · Arduino Christmas Calendar`;

  calendarView.hidden = true;
  reader.hidden = false;
}

const dayHash = (day) => '#day-' + String(day).padStart(2, '0');
document.querySelector('#back').addEventListener('click', () => navigate(''));
document.querySelector('#prev').addEventListener('click', () => navigate(dayHash(currentDay() - 1)));
document.querySelector('#next').addEventListener('click', () => navigate(dayHash(currentDay() + 1)));
document.addEventListener('keydown', (e) => {
  if (e.key === 'Escape' && !reader.hidden) navigate('');
});
window.addEventListener('popstate', render);

// ---------- Background snow ----------
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

render();
