# HOWTO install as a service (Linux)

1. Install kanata.
2. Copy the configuration file to a system wide place. (We use `/etc/kanata`.)
2. Install the service description for kanata.
3. (re)start the system service.
4. Enable it to auto-start on boot.

```
mkdir /etc/kanata
cp colemax-maxtend.kbd /etc/kanata
sudo install -m 644 kanata.service /lib/systemd/system/kanata.service
# sudo systemctl daemon-reload # maybe this will be required when changing the service file
sudo systemctl start kanata
sudo systemctl enable kanata
```
