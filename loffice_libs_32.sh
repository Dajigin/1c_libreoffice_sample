#!/bin/bash
# Создание символических ссылок на библиотеки LibreOffice SDK

# Поменяйте на свой путь к LibreOffice SDK:
export OFFICE_SDK=/usr/lib64/libreoffice/sdk
##########################################

if [ "$USER" != "root" ]
then
    echo 'Ошибка: скрипт должен быть запущен от имени root. Используйтe команду для запуска:
sudo ./loffice_libs.sh'
    exit
fi

ln -s -t /usr/lib/ $OFFICE_SDK/lib/libuno_cppu.so
ln -s -t /usr/lib/ $OFFICE_SDK/lib/libuno_sal.so
ln -s -t /usr/lib/ $OFFICE_SDK/lib/libuno_cppuhelpergcc3.so
