#!/bin/sh
if [ "$USER" != "root" ]
then
    echo 'Ошибка: скрипт должен быть запущен от имени root. Используйтe команду для запуска:
sudo ./install_tools.sh'
    exit
fi

apt install libreoffice-dev-common libreoffice-dev build-essential cmake uuid-dev
