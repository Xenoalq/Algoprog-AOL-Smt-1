#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int i = 0; // ini sebagai variabel global yang akan digunakan untuk count
int count = -1; // yang ini untuk search itu ada atau tidak

void exitProgram(){ // buat tampilin pesan program exit
	printf ("Thank You for using the program\n");
	printf ("Goodbye\n");
}

struct data{ //buat kelompokin data dalam satu kelompok yang berupa struct
	char location[50];
	char city[50];
	int price;
	int rooms;
	int bath;
	int park;
	char type[30];
	char furnish[30];
} hotel[4001];

int input(){ // berupa tampilan menu yang bisa dipilih dari 1-5 
	int menu;
	printf ("Hotel Finder Menu:\n");
	printf ("What do you want?\n");
    printf ("1. Display Data\n");
    printf ("2. Search Data\n");
    printf ("3. Sort Data\n");
    printf ("4. Export Data\n");
    printf ("5. Exit\n");
    printf ("Choose your choice: ");
    scanf (" %d", &menu); getchar();
    return menu;
}

void read(){ // ini untuk membaca file csv. yang akan diujikan yang berisikan, location, city
			// price, rooms, bathroom, car park, type, dan furnish.
	FILE *data = fopen("file.csv", "r");
	char header[200];
	fscanf (data, "%[^\n]\n", &header);
	
	while(!feof(data)){
		fscanf(data,"%[^;];%[^;];%d;%d;%d;%d;%[^;];%[^\n]\n", 
		&hotel[i].location, &hotel[i].city, &hotel[i].price, 
		&hotel[i].rooms, &hotel[i].bath, &hotel[i].park, &hotel[i].type, 
		&hotel[i].furnish);
		i++;
	}
	fclose(data);
}

int getdisplay(){ // buat menampilkan berapa baris yang ingin di display
	int baris;
	do{
	printf ("Number of rows: "); scanf ("%d", &baris);
		if(baris < 1){
			printf ("Wrong option");
		}
	} while (baris < 1);
	return baris;
}

void display(){ //function yang yang digunakan untuk menampilkan data / isi file sesuai dengan getdisplay
				// yaitu berapa baris yang diinginkan
	int baris = getdisplay();
		
	if (i < baris){
		baris = i;
	}
		printf("%-28s", "Location"); printf("%-19s", "City"); printf("%-13s", "Price"); printf("%-8s", "Rooms"); 
		printf("%-13s", "Bathrooms"); printf("%-12s", "Carpark"); printf("%-14s", "Type"); printf("%-11s\n", "Furnish");
	
    for (int i = 0; i < baris; i++) {
        printf("%-28s", hotel[i].location); printf("%-19s", hotel[i].city); printf("%-13d", hotel[i].price); printf("%-8d", hotel[i].rooms);
        printf("%-13d", hotel[i].bath); printf("%-12d", hotel[i].park); printf("%-14s", hotel[i].type);printf("%-11s\n", hotel[i].furnish);
    }
	printf ("\n");
	
}

void displaySearch(int i){ // penggunaannya sama seperti function display yaitu untuk menampilkan data
	printf("%-28s", hotel[i].location); printf("%-19s", hotel[i].city); printf("%-13d", hotel[i].price); printf("%-8d", hotel[i].rooms);
    printf("%-13d", hotel[i].bath); printf("%-12d", hotel[i].park); printf("%-14s", hotel[i].type); printf("%-11s\n", hotel[i].furnish);
	
}

void findStr(char coloumn[], char point[]){
	  for (int j = 0; j < i; j++) {
        if (
            strcasecmp(coloumn, "Location") == 0 && strcasecmp(point, hotel[j].location) == 0 ||
            strcasecmp(coloumn, "City") == 0 && strcasecmp(point, hotel[j].city) == 0 ||
            strcasecmp(coloumn, "Type") == 0  && strcasecmp(point, hotel[j].type) == 0 ||
            strcasecmp(coloumn, "Furnish") == 0  && strcasecmp(point, hotel[j].furnish) == 0){
            count++;
        }
    }
    if (count == -1){
		printf ("Data not found\n");
	}
	else{
		printf ("Data was found. This is the data:\n");
		printf("%-28s", "Location"); printf("%-19s", "City"); printf("%-13s", "Price"); printf("%-8s", "Rooms");
	    printf("%-13s", "Bathrooms"); printf("%-12s", "Carpark"); printf("%-14s", "Type"); printf("%-11s\n", "Furnish"); 
	    
	    if ((strcasecmp(coloumn, "Location") == 0 || strcasecmp(coloumn, "location") == 0)){
	        for (int j = 0; j < i; j++) {
	            if (strcasecmp(point, hotel[j].location) == 0){
	               displaySearch(j);
	            }
	        }
        } 
		else if ((strcasecmp(coloumn, "City") == 0 || strcasecmp(coloumn, "city") == 0)){
	        for (int j = 0; j < i; j++) {
	            if (strcasecmp(point, hotel[j].city) == 0){
	                displaySearch(j);
	            }
	        }
	    } 
		else if ((strcasecmp(coloumn, "Type") == 0 || strcasecmp(coloumn, "type") == 0)){
	        for (int j = 0; j < i; j++) {
	            if (strcasecmp(point, hotel[j].type) == 0){
	               displaySearch(j);
	            }
	        }
	    }
		else if ((strcasecmp(coloumn, "Furnish") == 0 || strcasecmp(coloumn, "furnish") == 0)){
	        for (int j = 0; j < i; j++) {
	            if (strcasecmp(point, hotel[j].furnish) == 0){
	                displaySearch(j);
	            }
	        }
	    }
	    getchar();
	}
	/* function ini berfungsi untuk mencari data berupa bentuk string dan hanya membaca stringnya saja
	search yang digunakan adalah linear search yang memanggil displaySearch, dan digunakan juga strcasecmp
	agar saat data yang ingin dicari tidak terbatas dengan perbedaan huruf kapital dan kecil */
}

void findInt(char coloumn[], int point){
	 for (int j = 0; j < i; j++) {
   		if (
	    	(strcasecmp(coloumn, "Price") == 0  && hotel[j].price == point) ||
	        (strcasecmp(coloumn, "Rooms") == 0  && hotel[j].rooms == point) ||
	        (strcasecmp(coloumn, "Bathrooms") == 0 && hotel[j].bath == point) ||
	        (strcasecmp(coloumn, "CarPark") == 0  && hotel[j].park == point)){
				count++;
		}
	}
	
	if(count == -1){
		printf("Data not found\n");
	}
	else{
		printf("%-28s", "Location"); printf("%-19s", "City"); printf("%-13s", "Price"); printf("%-8s", "Rooms");
	    printf("%-13s", "Bathrooms"); printf("%-12s", "Carpark"); printf("%-14s", "Type"); printf("%-11s\n", "Furnish");
	    
	    if (strcasecmp(coloumn, "Price") == 0 ){
	        for (int j = 0; j < i; j++) {
	            if (point == hotel[j].price){
	               displaySearch(j);
	            }
	        }
        } 
		else if (strcasecmp(coloumn, "Rooms") == 0 ){
	        for (int j = 0; j < i; j++) {
	            if (point == hotel[j].rooms){
	                displaySearch(j);
	            }
	        }
	    } 
		else if (strcasecmp(coloumn, "Bathrooms") == 0){
	        for (int j = 0; j < i; j++) {
	            if (point == hotel[j].bath){
	               displaySearch(j);
	            }
	        }
	    }
		else if (strcasecmp(coloumn, "CarPark") == 0 ){
	        for (int j = 0; j < i; j++) {
	            if (point == hotel[j].park){
	                displaySearch(j);
	            }
	        }
	    }
	}
	/* function ini sama seperti sebelumnya yaitu untuk search tapi hanya search integer sama sama menggunakan linear 
	search yang akan mengeluarkan data jika point dan hasil data sama. pencarian data karena tidak terbatas dengan huruf kapital dan kecil */
}

void inputSearch(){
	char coloumn[11];
	int findInte;
	char findString[100];
	
	do{
		printf("Choose column: ");
        scanf("%s", coloumn);
        getchar();  

        if (strcasecmp(coloumn, "location") != 0 && strcasecmp(coloumn, "city") != 0 &&
            strcasecmp(coloumn, "price") != 0 && strcasecmp(coloumn, "rooms") != 0 &&
            strcasecmp(coloumn, "bathrooms") != 0 && strcasecmp(coloumn, "carpark") != 0 &&
            strcasecmp(coloumn, "type") != 0 && strcasecmp(coloumn, "furnish") != 0) {
            printf("Wrong Option\n"); getchar();
        }
    } while (strcasecmp(coloumn, "location") != 0 && strcasecmp(coloumn, "city") != 0 &&
             strcasecmp(coloumn, "price") != 0 && strcasecmp(coloumn, "rooms") != 0 &&
             strcasecmp(coloumn, "bathrooms") != 0 && strcasecmp(coloumn, "carpark") != 0 &&
             strcasecmp(coloumn, "type") != 0 && strcasecmp(coloumn, "furnish") != 0);

    if (strcasecmp(coloumn, "location") == 0 || strcasecmp(coloumn, "city") == 0 ||
        strcasecmp(coloumn, "type") == 0 || strcasecmp(coloumn, "furnish") == 0) {
        printf("What data do you want? ");
        scanf("%[^\n]", findString);
        findStr(coloumn, findString);
   	 	printf ("Press any key to continue......\n"); getchar();
    } else if (strcasecmp(coloumn, "price") == 0 || strcasecmp(coloumn, "rooms") == 0 ||
               strcasecmp(coloumn, "bathrooms") == 0 || strcasecmp(coloumn, "carpark") == 0) {
        printf("What data do you want to find? ");
        scanf("%d", &findInte);
        getchar();  
        findInt(coloumn, findInte);
    }
    /* ini merupakan function untuk menjalankan case ke 2 berupa search yang berisikan do-while
    berupa input kolom dan data yang mau dicari. jika input tidak sesuai maka akan looping ulang hingga sesuai 
    setelah mendapat data yang sesuai maka masuk ke if-else yang menentukan kolom yang didapatkan berupa int atau string
    yang akan berlanjut ke function sebelumnya yaitu findStr atau findInt. */
}

void sortStr(struct data array[], int L, int R, char to[], int kondisi){
	int n = 0;
	if (L >= R){
		return;
	}
	int mid = (L + R) / 2;
	
	sortStr(array, L , mid, to, kondisi);
	sortStr(array, mid + 1, R, to, kondisi);
	
	int left = L, right = mid + 1;
	struct data temp[R - L + 1];
	
	while(left <= mid && right <= R){
		int temps;
		if(strcmp(to, "location") == 0 || strcmp(to, "Location") == 0){
			temps = strcmp(array[left].location, array[right].location);
		}
		else if(strcmp(to, "city") == 0 || strcmp(to, "City") == 0){
			temps = strcmp(array[left].city, array[right].city);
		}
		else if(strcmp(to, "type") == 0 || strcmp(to, "Type") == 0){
			temps = strcmp(array[left].type, array[right].type);
		}
		else if(strcmp(to, "furnish") == 0 || strcmp(to, "Furnish") == 0){
			temps = strcmp(array[left].furnish, array[right].furnish);
		}
		
		if((kondisi && temps < 0) || (!kondisi && temps > 0)){
			temp[n++] = array[left++];
		} else{
			temp[n++] = array[right++];
		}
	}
	
	while(left <= mid){
		temp[n++] = array[left++];
	}
	while(right <= R){
		temp[n++] = array[right++];
	}
	
	for(int i = 0; i < n; i++){
		array[L + i] = temp[i];
	}
	/* function ini digunakan untuk menyorting string yang dilakukan dengan merge sort, lalu
	sebagai pengganti strcasecmp, bisa juga menggunakan perbandingan yang satu menggunakan kapital 
	dan satunya tidak agar memiliki fungsi seperti strcasecmp. terdapat if-else yang bila kondisi
	true, maka akan menginput data yang paling kiri terlebih dahulu */
}

void sortInt(struct data array[], int L, int R, char to[], int kondisi){
	int n = 0;
	if (L >= R){
		return;
	}
	int mid = (L + R) / 2;
	
	sortInt(array, L , mid, to, kondisi);
	sortInt(array, mid + 1, R, to, kondisi);
	
	int left = L, right = mid + 1;
	struct data temp[R - L + 1];
	
	while(left <= mid && right <= R){
		int temps;
		if(strcmp(to, "price") == 0 || strcmp(to, "Price") == 0){
			temps = array[left].price - array[right].price;
		}
		else if(strcmp(to, "rooms") == 0 || strcmp(to, "Rooms") == 0){
			temps = array[left].rooms - array[right].rooms;
		}
		else if(strcmp(to, "bathroom") == 0 || strcmp(to, "Bathroom") == 0){
			temps = array[left].bath - array[right].bath;
		}
		else if(strcmp(to, "carpark") == 0 || strcmp(to, "Carpark") == 0){
			temps = array[left].park - array[right].park;
		}
		
		if((kondisi && temps < 0) || (!kondisi && temps > 0)){
			temp[n++] = array[left++];
		}
		else{
			temp[n++] = array[right++];
		}
	}
	
	while(left <= mid){
		temp[n++] = array[left++];
	}
	while(right <= R){
		temp[n++] = array[right++];
	}
	
	for(int i = 0; i < n; i++){
		array[L + i] = temp[i];
	}
		/* function ini digunakan untuk menyorting int yang dilakukan dengan merge sort, lalu
	sebagai pengganti strcasecmp, bisa juga menggunakan perbandingan yang satu menggunakan kapital 
	dan satunya tidak agar memiliki fungsi seperti strcasecmp. terdapat if-else yang bila kondisi
	true, maka akan menginput data yang paling kiri terlebih dahulu */
}
	
void displaySorting(){ // function yang menampilkan output setelah melakukan sorting
	printf ("Data was found. This is the data:\n");
	printf("%-28s", "Location"); printf("%-19s", "City"); printf("%-13s", "Price"); printf("%-8s", "Rooms");
    printf("%-13s", "Bathrooms"); printf("%-12s", "Carpark"); printf("%-14s", "Type"); printf("%-11s\n", "Furnish");
		printf ("\n");
    
	    for (int i = 0; i < 20; i++) { //dibatesin hingga 20 data
	        printf("%-28s", hotel[i].location); printf("%-19s", hotel[i].city); printf("%-13d", hotel[i].price); printf("%-8d", hotel[i].rooms);
	        printf("%-13d", hotel[i].bath); printf("%-12d", hotel[i].park); printf("%-14s", hotel[i].type); printf("%-11s\n", hotel[i].furnish);
			}
			printf ("\n");
}

void inputSort(){
	char coloumn[11];
	char to[11];
	int kondisi;
	do{
		printf("Choose coloumn: (using Capital)\n"); scanf("%s", coloumn); getchar();
		if(strcmp(coloumn, "Location") != 0 && strcmp(coloumn, "City") != 0 && strcmp(coloumn, "Price") != 0 && strcmp(coloumn, "Rooms") != 0 && strcmp(coloumn, "Bathroom") != 0 && strcmp(coloumn, "Carpark") != 0 && strcmp(coloumn, "Type") != 0 && strcmp(coloumn, "Furnish") != 0){
				printf("Wrong Option\n");
			}
	} while(strcmp(coloumn, "Location") != 0 && strcmp(coloumn, "City") != 0 && strcmp(coloumn, "Price") != 0 && strcmp(coloumn, "Rooms") != 0 && strcmp(coloumn, "Bathroom") != 0 && strcmp(coloumn, "Carpark") != 0 && strcmp(coloumn, "Type") != 0 && strcmp(coloumn, "Furnish") != 0);
			
	if(strcmp(coloumn, "Location") == 0 || strcmp(coloumn, "City") == 0 ||strcmp(coloumn, "Type") == 0 || strcmp(coloumn, "Furnish") == 0 ){
				do{
				printf("Sort ascending or descending? (a/d)\n"); scanf("%s", to);getchar();
				if(strcmp(to, "a") != 0 && strcmp(to, "d") != 0 && strcmp(to, "ascending") != 0 && strcmp(to, "descending") != 0){
					printf("Wrong Option\n");
					printf("Choose coloumn:\n = %s\n", coloumn);
						}
				} while(strcmp(to, "a") != 0 && strcmp(to, "d") != 0 && strcmp(to, "ascending") != 0 && strcmp(to, "descending") != 0);
				if(strcmp(to, "a") == 0 || strcmp(to, "ascending") == 0){
					kondisi = 1;
				}
				else{
					kondisi = 0;
				}
				sortStr(hotel, 0, i - 1, coloumn, kondisi);
				displaySorting();
		 
		 } else if(strcmp(coloumn, "Price") == 0 || strcmp(coloumn, "Rooms") == 0 || strcmp(coloumn, "Bathroom") == 0 || strcmp(coloumn, "Carpark") == 0){
				printf("Sort ascending or descending? (a/d)\n");
				do{
				scanf("%s", to); 
				getchar();
			} while(strcmp(to, "a") != 0 && strcmp(to, "d") != 0 && strcmp(to, "ascending") != 0 && strcmp(to, "descending") != 0);
			
			if(strcmp(to, "a") == 0 || strcmp(to, "ascending") == 0){
					kondisi = 1;
				}
				else{
					kondisi = 0;
				}
			sortInt(hotel, 0, i - 1, coloumn, kondisi);
			displaySorting();
		}
	/* ini merupakan function untuk menjalankan case ke 3 berupa sorting yang berisikan do-while
    berupa input kolom dan data yang mau dicari. jika input tidak sesuai maka akan looping ulang hingga sesuai 
    setelah mendapat data yang sesuai maka masuk ke if-else yang menentukan kolom yang didapatkan berupa int atau string
    yang akan berlanjut ke function sebelumnya yaitu sortStr atau sortInt. */
}
	
void Write(FILE* update){
	fprintf (update, "%-12s %-12s %-12s %-12s %-12s %-12s %-12s %-12s\n", "Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnished");
	
	for (int j = 0; j < i; j++){
		fprintf (update, "%-12s %-12s %-12d %-12d %-12d %-12d %-12s %-12s\n",
            hotel[i].location, hotel[i].city, hotel[i].price,
        	hotel[i].rooms, hotel[i].bath, hotel[i].park,
        	hotel[i].type, hotel[i].furnish);
	}
	/* function ini digunakan untuk menulis data dari file sebelumnya dan membuat file baru
	yang berisikan data sebelumnya yang dipindahkan ke file baru */
}

void New(){
	char newFile[100];
	printf ("Input name: ");
	scanf ("%[^\n]", newFile);
	getchar ();
	strcat(newFile, ".csv");
	
	FILE *x = fopen(newFile, "w");
	Write(x); 
	fclose(x);
	printf ("File was saved\n");
	printf ("\n");
	/* function ini digunakan untuk menyimpan data kedalam file baru yang sudah dijalankan sebelumnya
	apabila proses berhasil, maka akan muncul pesan file was saved di folder penyimpanan*/
}

void menu(){ // ini buat memanggil case yang berisikan function sudah ada sebelumnya dan menjalankan functionnya
	int menu;
	do{
		menu = input();
		switch(menu){
			case 1: 
				display();
				break;
			
			case 2: 
				inputSearch();
				break;
			
			case 3: 
				inputSort();
				break;
			
			case 4: 
				New();
				break;
			
			case 5: 
				exitProgram();
				break;
			
		}
	if (menu == 5){
		break;
	}
	} while (1);
}

int main() {
	read(); // membaca file
	menu(); // masuk ke case berupa function yang akan dijalankan
	return 0;
}


 

