
Debian
====================
This directory contains files used to package binkdogcoind/binkdogcoin-qt
for Debian-based Linux systems. If you compile binkdogcoind/binkdogcoin-qt yourself, there are some useful files here.

## binkdogcoin: URI support ##


binkdogcoin-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install binkdogcoin-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your binkdogcoinqt binary to `/usr/bin`
and the `../../share/pixmaps/binkdogcoin128.png` to `/usr/share/pixmaps`

binkdogcoin-qt.protocol (KDE)

