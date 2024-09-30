#include<stdio.h>
#define students 5
#define subjects 5
int main()
{
	int marks[students][subjects],i,j;
	float sub_avg[subjects]={0};
	float stud_avg[students]={0};
	int stud_below50 = 0;
	// Input marks for 5 students in 5 subjects.
	printf("Enter the marks obtained by %d students in %d subjects:\n", students,subjects );
	for ( i = 0; i < students; i++) {
	printf("Marks obtained by Student %d:\n", i + 1);
	for ( j = 0; j < subjects; j++) {
	printf("Subject %d: ", j + 1);
	scanf("%d", &marks[i][j]);
	sub_avg[j] += marks[i][j]; // Calculate total for each subject
	}
	}
	// Calculate average for each subject
	for ( j = 0; j < subjects; j++) {
	sub_avg[j] /= students;
	}
	// Calculate average for each student and count those below 50
	for ( i = 0; i < students; i++) {
	int totalMarks = 0;
	for ( j = 0; j < subjects; j++) {
	totalMarks += marks[i][j];
	}
	stud_avg[i] = (float)totalMarks / subjects;
	if (stud_avg[i] < 50) {
	stud_below50++;
	}
	}
	// Display the average marks obtained by each student
	printf("\nAverage marks obtained by each student:\n");

	for ( i = 0; i < students; i++) {
	printf("Student %d: %.2f\n", i + 1, stud_avg[i]);
	}
	// Display the number of students who scored below 50 in their average
	printf("\nNumber of students who scored below 50 in their average: %d\n",
	stud_below50);
	// Display the scores obtained by every student
	printf("\nScores obtained by each student:\n");
	for ( i = 0; i < students; i++) {
	printf("Student %d: ", i + 1);
	for ( j = 0; j < subjects; j++) {
	printf("%d ", marks[i][j]);
	}
	printf("\n");
	}
	return 0;
}