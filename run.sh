#!/bin/bash
PROGRAM="structtest"
escape_prog() {
    echo -e "\n"
    read -p "Press any key to exit:  " DONE
    exit 0
}


    echo -e "[0  %] Checking for previous versions..."
    if [ -e "$PROGRAM" ]; then
        echo -e "[10 %] Removing previous versions..."
        rm $PROGRAM

        if [ -e "$PROGRAM" ]; then
            failure_close
        fi
    fi

    echo -e "[25 %] Begin make..."
    make

    echo -e "[50 %] Verifying make..."

    if [ -e "$PROGRAM" ]; then
        echo -e "[75 %] Executable exists..."

        echo -e "[90 %] Changing executable Persmissions..."
        chmod 700 ./$PROGRAM

        echo -e "[100%] Ready to launch..."
        read -p "Press any key to RUN / [N] to exit:  " DONE

        if [ "$DONE" == 'N' ]; then
            escape_prog
        fi

        clear

        ./$PROGRAM

        escape_prog
    fi
