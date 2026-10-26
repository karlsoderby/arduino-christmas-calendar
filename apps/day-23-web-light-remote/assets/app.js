const ui = new WebUI();
const statusEl = document.querySelector('#status');
const buttons = document.querySelectorAll('button[data-mode]');

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
    ui.send_message('set_mode', { mode: Number(button.dataset.mode) });
    buttons.forEach((b) => b.classList.remove('active'));
    button.classList.add('active');
  });
});
