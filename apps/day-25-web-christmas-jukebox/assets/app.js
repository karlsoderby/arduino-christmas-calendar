const ui = new WebUI();
const statusEl = document.querySelector('#status');
const nowPlaying = document.querySelector('#now-playing');
const countdown = document.querySelector('#countdown');
const buttons = document.querySelectorAll('button[data-song]');

ui.on_connect(() => {
  statusEl.textContent = 'Connected';
  statusEl.classList.add('online');
});

ui.on_disconnect(() => {
  statusEl.textContent = 'Disconnected';
  statusEl.classList.remove('online');
});

buttons.forEach((button) => {
  button.addEventListener('click', () => {
    ui.send_message('play_song', { song: Number(button.dataset.song) });
    nowPlaying.textContent = 'Now playing: ' + button.textContent;
  });
});

// Days until Christmas
const today = new Date();
today.setHours(0, 0, 0, 0);
let christmas = new Date(today.getFullYear(), 11, 25);
if (today > christmas) {
  christmas = new Date(today.getFullYear() + 1, 11, 25);
}
const days = Math.round((christmas - today) / 86400000);
countdown.textContent = days === 0 ? '🎄 Merry Christmas! 🎄' : `${days} days until Christmas`;
