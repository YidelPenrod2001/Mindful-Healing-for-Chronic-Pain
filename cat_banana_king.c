#include <stdio.h>
#include <stdlib.h>

// Declaring global variables to store pain levels, 
// patient ages and patient histories
int age, painLevel;
char patientHistory[1000];

// Declaring a structure to store information on the healing program
struct HealingProgram {
	int medication;
	int exercise;
	int psychotherapy;
	int nutrition;
	int relaxation;
};

// Function to get patient information from user
void getPatientInfo(){
	printf("Please enter patient age: \n");
	scanf("%d", &age);
	printf("Please enter patient pain level (on a scale of 1 to 10): \n");
	scanf("%d", &painLevel);
	printf("Please enter patient medical history (please limit to 1000 characters): \n");
	scanf("%s", &patientHistory);
}

// Function to generate a healing program 
// based on the patient's age, pain level, and history
struct HealingProgram generateHealingProgram(){
	struct HealingProgram program;
	if (age < 18){ 
		// For young patients, focus on psychotherapy and relaxation
		program.psychotherapy = 5;
		program.relaxation = 5;
		program.medication = 3;
		program.exercise = 3;
		program.nutrition = 3;
	}
	else if (painLevel < 5){
		// Mild pain requires exercise, nutrition, and relaxation
		program.relaxation = 5;
		program.exercise = 5;
		program.nutrition = 5;
		program.psychotherapy = 3;
		program.medication = 3;
	}
	else if (painLevel >= 5 && painLevel <= 7){
		// For moderate pain, focus on medication, exercise, and relaxation
		program.medication = 5;
		program.exercise = 5;
		program.relaxation = 5;
		program.psychotherapy = 3;
		program.nutrition = 3;
		
	}
	else if (painLevel > 7){
		// For severe pain, focus on medication, psychotherapy, and relaxation
		program.medication = 5;
		program.psychotherapy = 5;
		program.relaxation = 5;
		program.exercise = 3;
		program.nutrition = 3;
	}
	return program;
}

// Function to display the healing program
void displayHealingProgram(struct HealingProgram program){
	printf("\nYour healing program includes the following components:\n");
	printf("Medication: %d \n", program.medication);
	printf("Exercise: %d \n", program.exercise);
	printf("Psychotherapy: %d \n", program.psychotherapy);
	printf("Nutrition: %d \n", program.nutrition);
	printf("Relaxation: %d \n", program.relaxation);
}

int main(){
	// Get patient information from user
	getPatientInfo();

	// Generate healing program based on the patient's age, pain level, and history
	struct HealingProgram healingProgram = generateHealingProgram();

	// Display generated healing program
	displayHealingProgram(healingProgram);
	
	return 0;
}