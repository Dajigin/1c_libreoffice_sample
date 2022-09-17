#!/bin/sh
if [ "$USER" != "root" ]
then
    echo 'Ошибка: скрипт должен быть запущен от имени root. Используйтe команду для запуска:
sudo ./loffice_libs.sh'
    exit
fi

apt install libreoffice-dev-common libreoffice-dev build-essential cmake
