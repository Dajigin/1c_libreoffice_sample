0. Если не установлен git, нужно его установить
Например: sudo apt install git

Клонировать репозиторий проекта. Например, в домашний каталог, подкаталог liboffice_sample:
git clone https://github.com/Dajigin/1c_libreoffice_sample.git ~/liboffice_sample

1. Установка инструментов
	1.1 Для тестирования компоненты дополнительных инструментов не требуется.

	1.2 Для сборки нужны: набор компиляторов gcc, компилятор g++, утилиты сборки make и cmake, Libre Office SDK.

		Примечание для AstraLinux: необходимо раскомментировать репозиторий repository-base в файле:
		sudo nano /etc/apt/sources.list
		после чего выполнить:
		sudo apt update
		
	Для установки на deb-based системах  можно запустить файл install_tools_deb.sh из склонированного репозитория.

2. Сборка

В Makefile в переменной PRJ измените путь к LibreOffice SDK на свой.

Откройте терминал, перейдите в каталог /libhello

Из терминала запустите файл инициализации окружения LibreOffice SDK (Находится в каталоге SDK. Например, у меня здесь: /usr/lib64/libreoffice/sdk/setsdkenv_unix).

В ТОЙ ЖЕ сессии терминала выполните "make clean" в каталоге libhello. При этом будут удалены файлы, созданные при предыдущей компиляции (если они есть).

