#include "Header.h"

void printMenu() {
	printf("Pick your options: \n");
	printf("1- Dodavanje novih clanova u clanovi.bin\n");
	printf("2- Citanje iz datoteke clanovi.bin\n");
	printf("3- Posudba filma.\n");
	printf("4- Zavrsetak programa.\n");
}

void printMoviesToScreen(char* moviesFileName) {
	FILE* file = fopen(moviesFileName, "rb");

	int counter;
	fread(&counter, sizeof(int), 1, file);
	printf("Counter: %d\n", counter);

	FILM* movie = (FILM*)malloc(counter * sizeof(FILM));
	fread(movie, sizeof(FILM), counter, file);
	fclose(file);

	for (int i = 0; i < counter; i++) {
		printf("Movie: %s rented by: %d.\n", movie[i].name, movie[i].memberId);
	}
	free(movie);
}

void addMember(char* fileName) {
	int memberCounter = 0;

	FILE* file = fopen(fileName, "rb+");
	if (file != NULL) {
		fread(&memberCounter, sizeof(int), 1, file);
	}
	else {
		file = fopen(fileName, "wb");
		fwrite(&memberCounter, sizeof(int), 1, file);
	}

	CLAN member;
	inputMember(&member);

	memberCounter++;
	rewind(file);
	fwrite(&memberCounter, sizeof(int), 1, file);

	fseek(file, 0, SEEK_END);
	fwrite(&member, sizeof(CLAN), 1, file);

	puts("\nMember added.\n");

	fclose(file);
}

void inputMember(CLAN* member) {
	printf("Enter member first name: ");
	scanf(" %[^\n]s", member->fName);

	printf("Enter member last name: ");
	scanf(" %[^\n]s", member->lName);

	printf("Enter member id: ");
	scanf("%d", &member->ID);
	getchar();

	printf("Enter memeber address: ");
	scanf(" %[^\n]s", member->address);

	printf("Enter member phone number: ");
	scanf(" %[^\n]s", member->phoneNumber);
}

void readFile(char* fileName, int id) {
	FILE* inFile = fopen(fileName, "rb");
	CLAN member;
	int memberCounter, i;
	if (inFile != NULL) {
		fread(&memberCounter, sizeof(int), 1, inFile);
		for (i = 0; i < memberCounter; i++) {
			fread(&member, sizeof(CLAN), 1, inFile);
			if (id == member.ID) {
				printf("\nName: %s %s\n", member.fName, member.lName);
				printf("ID: %d\nPhone num: %s\n", member.ID, member.phoneNumber);
				printf("Address: %s\n", member.address);
			}
			else if (id == -1) {
				printf("\nName: %s %s\n", member.fName, member.lName);
				printf("ID: %d\nPhone num: %s\n", member.ID, member.phoneNumber);
				printf("Address: %s\n", member.address);
			}
		}
		fclose(inFile);
	}
	puts("\n---- END OF FILE ----\n");
}

int exitProgram() {
	char str[3], c;
	int i = 0, counter = 0;
	puts("\nJeste li sigurni da zelite zavrsiti program?\n");
	do {
		printf("Unesi da/ne: ");
		fgets(str, 3, stdin);

		if (toupper(str[0]) == 'D' && toupper(str[1]) == 'A' && str[2] == '\0')
			exit(EXIT_SUCCESS);

	} while (checkCondition(str));
	return 1;
}

int checkCondition(char* str) {
	if (toupper(str[0]) == 'N' && toupper(str[1]) == 'E' && toupper(str[2]) == '\0') return 0;
	return 1;
}

void createMoviesFile(char* moviesFileName) {
	FILE* moviesFile = fopen(moviesFileName, "rb");
	if (moviesFile == NULL) {
		moviesFile = fopen(moviesFileName, "wb");
		int moviesCounter = 0;
		fwrite(&moviesCounter, sizeof(int), 1, moviesFile);
	}
	fclose(moviesFile);
}

void rentMovie(char* membersFileName, char* moviesFileName) {

	//Limit to only 4 movies
	int movieNumber;
	getMovieNumber(&movieNumber);

	//Checks if file exists creates it if it doesnt
	createMoviesFile(moviesFileName);

	int i; FILM movie;
	for (i = 0; i < movieNumber; i++) {

		//Enter info about the movie
		getMovieToRent(&movie);

		int memberExists, canRent;
		//Check if there is a member is matching movie.memberId
		memberExists = checkForMember(membersFileName, &movie);
		
		//Check if member has 4 movies already rented
		canRent = checkMemberRentStatus(moviesFileName, &movie);

		//If there is a matching memeber id and member has < 4 movies
		//allow the new movie to be rented and write it to file.
		//else print error
		if (memberExists && canRent) {
			registerRentedMovie(moviesFileName, &movie);
			printMoviesToScreen(moviesFileName);
		}
		else {
			printf("\nRenting failed.\nMember exists status: %d\n", memberExists);
			printf("Member can rent status: %d\n\n", canRent);
		}
	}
}

void getMovieNumber(int* movieNumber) {
	do {
		puts("How many movies do you what to checkout? (1 - 4)");
		scanf("%d", movieNumber);
	} while (*movieNumber <= 0 || *movieNumber > 4);
}

void getMovieToRent(FILM* movie) {
	printf("Enter movie name: ");
	scanf(" %[^\n]s", &movie->name);

	do {
		printf("Enter date in range (0 - 365): ");
		scanf("%d", &movie->date); getchar();
	} while (movie->date < 0 || movie->date > 365);

	printf("Enter member code: ");
	scanf("%d", &movie->memberId); getchar();
}

int checkForMember(char* memberFileName, FILM* movie) {
	FILE* members = fopen(memberFileName, "rb");
	if (members == NULL) return 0;

	int memberCounter;
	fread(&memberCounter, sizeof(int), 1, members);

	CLAN member;
	//read members one by one to see if there is a member with
	//the id matching movie.memberId
	while (fread(&member, sizeof(CLAN), 1, members) == 1) {
		if (member.ID == movie->memberId) {
			fclose(members);
			return 1;
		}
	}
	fclose(members);
	return 0;
}

int checkMemberRentStatus(char* moviesFileName, FILM* movie) {

	//Read entire file to memory
	FILE* movies = fopen(moviesFileName, "rb");

	int moviesCounter;
	fread(&moviesCounter, sizeof(int), 1, movies);

	FILM* movieArray = (FILM*)malloc(moviesCounter * sizeof(FILM));

	fread(movieArray, sizeof(FILM), moviesCounter, movies);
	int counter = 0;

	int flag = 0;
	for (int i = 0; i < moviesCounter; i++) {
		if (movie->memberId == movieArray[i].memberId)
			counter++;
		if (counter == 4) { flag = 1; break; }
	}

	fclose(movies);
	free(movieArray);

	if (flag) return 0;
	else return 1;
}

void registerRentedMovie(char* moviesFileName, FILM* movie) {

	//Again read entire file to memory
	FILE* inFile = fopen(moviesFileName, "rb");

	int moviesCounter;
	fread(&moviesCounter, sizeof(int), 1, inFile);

	FILM* movieArray = (FILM*)malloc(moviesCounter * sizeof(FILM));
	fread(movieArray, sizeof(FILM), moviesCounter, inFile);

	fclose(inFile);


	//Overwrite the old file and create a new one
	//but fill it with the old data so it looks the same
	//and add one extra movie to the end.
	FILE* outFile = fopen(moviesFileName, "wb");
	moviesCounter++;
	fwrite(&moviesCounter, sizeof(int), 1, outFile);
	fwrite(movieArray, sizeof(FILM), moviesCounter - 1, outFile);
	fwrite(movie, sizeof(FILM), 1, outFile);
	fclose(outFile);

	free(movieArray);
}