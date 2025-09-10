#include <stdio.h>
#include <string.h>

void convertString() {
    char a[101]; // function buat ubak kata menjadi kebalikkannya dan uabh menjadi kapital ngescan kata dan dibatasi 100 sesuai perintah
    printf ("Insert the word: ");
    scanf ("%[^\n]", a);

    int length = strlen(a); //ini kalo misal kepanjangan katanya
    if (length < 1 || length > 100) {
        printf ("The length of word is to long.\n");
        return;
    }

    for (int i = 0, j = length - 1; i < j; i++, j--) { // proses membalikkan urutan hurufnya
        char temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    printf ("After get inverse: %s\n", a);

    for (int i = 0; i < length; i++) { //proses ubah hurufnya dari kecil jadi kapital dan sebaliknya yang diambil 
        if (a[i] >= 'a' && a[i] <= 'z') { // dari kata yang sudah dibalik urutan hurufnya
            a[i] = a[i] - 'a' + 'A'; 
        } else if (a[i] >= 'A' && a[i] <= 'Z') {
            a[i] = a[i] - 'A' + 'a'; 
        }
    }
    printf ("After convert: %s\n", a);
    printf ("\n");
    printf ("*******************************************\n");
}

void exitProgram() { // function untuk menampilkan pesan saat exit program
    printf ("Goodbye!\n");
}

int main() {
	char menu;

    do {
        printf ("Word Inverse Menu:\n"); // ini buat tampilan menunya
        printf ("\n");
        printf ("1. Inverse\n");
        printf ("2. Exit\n");
        printf ("Choose your choice: ");
        scanf (" %c", &menu);
        
        while (getchar() != '\n');

        
        switch (menu) { // menunya bakal tampilin 1 dan 2 yang akan dipilih user
            case '1':
                convertString();
                break;

            case '2':
                exitProgram();
                break;

            default:
                printf ("Please Select the correct number.\n");
        }

    } while (menu != '2');

    return 0;
}



