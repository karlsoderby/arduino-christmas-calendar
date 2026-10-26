// Adds a few falling snowflakes to the page background.
for (let i = 0; i < 30; i++) {
  const flake = document.createElement('span');
  flake.className = 'snowflake';
  flake.textContent = '❄';
  flake.style.left = Math.random() * 100 + 'vw';
  flake.style.fontSize = 0.6 + Math.random() * 1.2 + 'em';
  flake.style.animationDuration = 6 + Math.random() * 8 + 's';
  flake.style.animationDelay = -Math.random() * 14 + 's';
  document.body.appendChild(flake);
}
