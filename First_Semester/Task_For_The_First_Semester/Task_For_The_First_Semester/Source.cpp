// Beauty Competition Program
#include <iostream>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <cmath>
#include <fstream>
#include <iomanip>

#define N 30 // N is the number of possible indexes in the array_participants

using namespace std;

// Struct for the participants' array
struct array_participants
{
	string serial_number;
	string name;
	unsigned int age;
	string sex;
	float hip_circ;
	float shoulder_circ;
	float neck_circ;
	float calf_circ;
	float proportion;
};


// Prototypes of all Functions

int main();
array_participants input();
void array_participants_output(array_participants array_a);
unsigned main_menu(unsigned &m_menu);
void sub_menu_1();
void sub_menu_1_1(int& n_n, int& i_i, int j_j, array_participants array_main_m1[]);

void sub_menu_2();

void sub_menu_3();
void sub_menu_3_1();
void name_update(string& name_update);
void name_checking(array_participants name_arr, string name_look_f, bool& name_check);
void sub_menu_yes_or_no(string name_look_yes_or_no);
void searching_by_name_f(array_participants name_arr_repeat, string& name_look_subf, bool& name_check_repeat, bool& double_check_f);
void min_agef(array_participants min_age_var, unsigned& min_age);
void youngest(array_participants youngest_people, int i_3_2_f, unsigned min_age_f);

void sub_menu_6();
void sex_checking(array_participants name_arr, string name_look_f, bool& name_check);

void fill_subarrays(array_participants arr[], array_participants arr_filling[], int n, int& n2, int age1, int age2); 
void out_subarrays(array_participants arr[], int n2, int age1, int age2);

void if_function_array(array_participants arr[], array_participants array[], int sub_n, int age1, int age2);
void bubbleSort_proportion(array_participants arr[], int n);

//Sort 
void bubbleSort_age(array_participants arr[], int n);
void bubbleSort_name_age(array_participants arr[], int n);
void swapping(array_participants arr[], int j);


//int partition(array_participants  arr[], int low, int high);
//void quickSort(array_participants  arr[], int low, int high);


void navigation(unsigned& main_menu_var_nav, int n, array_participants arr[]);
void congratz_1();
void exit(unsigned& main_menu_var_exit, int n, array_participants arr[]);



// Main Function Call
int main()
{
	fstream outstream;
	fstream instream;
	array_participants array_main[N];
	array_participants array14_16[N];
	int n14_16 = 0;
	array_participants array17_19[N];
	int n17_19 = 0;
	array_participants array20_22[N];
	int n20_22 = 0;
	array_participants array23_25[N];
	array_participants winner1[N];
	array_participants winner2[N];
	array_participants winner3[N];
	array_participants winner4[N];
	int n23_25 = 0;
	int i;
	int* p;
	i = 0;
	int n;
	n = 0;
	bool menu7;
	menu7 = false;
	unsigned main_menu_var;
	main_menu(main_menu_var);

	instream.open("Saved_List.dat", ios::in | ios::binary);
	int file_size;
	int number_of_elements;
	instream.seekg(0, ios::end);
	file_size = instream.tellg();
	instream.seekg(0, ios::beg);
	instream.read((char*)&array_main, file_size);
	instream.close();
	n = file_size / sizeof(array_participants);

	// Main Menu Loop
	do
	{
		cout << '\n' << "Your Choice: ";
		cin >> main_menu_var;
		switch (main_menu_var)
		{
		case 1: // Adding new Participants
			{
				system("cls");
				cout << "In the Process of Adding a New Participant..." << "\n" << "\n";
				cout << "Enter the Number of Participants to be added: ";
				
				i = n;
				cin >> n;

				if (i + n > N)
				{
					do {
						cout << '\n' << "You have exceeded the number of possible constenstants that can be included. Please input a smaller number: ";
						cin >> n;
					} while (i + n > N);
				}

				int j;
				j = i;

				for (i; i < (n + j); i++)
				{
					array_main[i] = input();
				};

				if (n > 0) {
					congratz_1();
					
				}
				n = i;

				sub_menu_1();

				int sub_menu1;

				do {
					cout << "Your Option for this Submenu: ";
					cin >> sub_menu1;

					switch (sub_menu1)
					{
					case 1:
						sub_menu_1_1(n, i, j, array_main);
						sub_menu1 = 0;
						sub_menu_1();
						break;
					case 2:
						main_menu(main_menu_var);
						break;
					case 3:
						exit(main_menu_var, n, array_main);
						break;
					};
				} while ((sub_menu1 > 3) || (sub_menu1 == 0));

				int i_store;
				i_store = i;
				break;
			};
		case 2: // Output of all Participants
			{
			system("cls");

			if (n == 0) {
				cout << "There are currently no enlisted contenstants!" << '\n';
			}
			else
			{
				cout << "Here is a list of all currently enrolled contenstants:" << '\n';
				for (int i_zero = 0; i_zero < (n); i_zero++)
				{
					cout << "--------------------------------------------" << "\n" << "Contestant " << i_zero + 1 << '\n';
					array_participants_output(array_main[i_zero]);
					
				};
			}

			navigation(main_menu_var, n, array_main);
			break;
		}
		case 3: // Search in main array and Sort by age
		{
			sub_menu_3();
			int sub_menu3;

			do {
				cout << "Your Option for this Submenu: ";
				cin >> sub_menu3;

				switch (sub_menu3)
				{
				case 1: // Name Search
				{
					system("cls");
					if (n == 0)
					{
						cout << "There are currently no enlisted contenstants!" << '\n';
						navigation(main_menu_var, n, array_main);
					}
					else
					{
						string name_look;
						cout << "Gathering information..." << '\n' << '\n';

						cout << "Please input the name of the person you are looking for: ";
						cin.ignore(1000, '\n');
						getline(cin, name_look);

						bool check_of_check;
						check_of_check = false;
						bool name_check;
						bool double_check;
						bool rep_check;
						rep_check = true;
						for (int i_3_1 = 0; i_3_1 < n; i_3_1++)
						{
							name_checking(array_main[i_3_1], name_look, name_check);
							if (name_check)
							{
								if (rep_check == true) cout << '\n' << "We have found a match\n";
								array_participants_output(array_main[i_3_1]);
								check_of_check = true;
								rep_check = false;
							};
						};
						int yes_no;
						if (check_of_check == false)
						{
							sub_menu_yes_or_no(name_look);
							do {
								cout << "\n" << "Your Option for this Submenu: ";
								cin >> yes_no;


								switch (yes_no)
								{
								case 1:   ///////////////////////////////////////////
								{
									system("cls");
									name_update(name_look);
									for (int i_3_1 = 0; i_3_1 < n; i_3_1++)
									{
										searching_by_name_f(array_main[i_3_1], name_look, name_check, double_check);
									}
									yes_no = 0;
									if (name_check == false && double_check == false)
									{
										sub_menu_yes_or_no(name_look);
									}
									else
									{
										sub_menu_3_1();
									};
									break;
								}
								case 2:
								{
									sub_menu_2();
									int sub_menu2;

									do {
										cout << "Your Option for this Submenu: ";
										cin >> sub_menu2;

										switch (sub_menu2)
										{
										case 1:
											main_menu(main_menu_var);
											break;
										case 2:
											exit(main_menu_var, n, array_main);
											break;
										};
									} while ((sub_menu2 > 2) || (sub_menu2 == 0));
									break;
								}
								};
							} while ((yes_no > 2) || (yes_no == 0));
						}
						else
						{
							sub_menu_3_1();
							do
							{
								cout << "\n" << "Your Option for this Submenu: ";
								cin >> yes_no;

								switch (yes_no)
								{
								case 1:							// working on it
								{

									system("cls");
									name_update(name_look);
									for (int i_3_1 = 0; i_3_1 < n; i_3_1++)
									{
										searching_by_name_f(array_main[i_3_1], name_look, name_check, double_check);
									}

									yes_no = 0;
									if (name_check == false && double_check == false)
									{
										sub_menu_yes_or_no(name_look);
									}
									else
									{
										sub_menu_3_1();
									};
									break;
								}
								case 2:
								{
									sub_menu_2();
									int sub_menu2;

									do {
										cout << "Your Option for this Submenu: ";
										cin >> sub_menu2;

										switch (sub_menu2)
										{
										case 1:
											main_menu(main_menu_var);
											break;
										case 2:
											exit(main_menu_var, n ,array_main);
											break;
										};
									} while ((sub_menu2 > 2) || (sub_menu2 == 0));
									break;
								}
								};
							} while ((yes_no > 2) || (yes_no == 0));
						};
					};
					break;
				}
				case 2: // Age Search
				{
					system("cls");

					if (n == 0)
					{
						cout << "There are currently no enlisted contenstants!" << '\n';
					}
					else
					{
						unsigned min_age;
						min_age = INT_MAX;

						for (int i_3_2 = 0; i_3_2 < n; i_3_2++)
						{
							min_agef(array_main[i_3_2], min_age);

						};
						cout << min_age << '\n';
						cout << "These are the youngest constestant(s)!" << '\n' << '\n';
						for (int i_3_2 = 0; i_3_2 < n; i_3_2++)
						{

							youngest(array_main[i_3_2], i_3_2, min_age);
						}
					}
					sub_menu_2();
					int sub_menu2;

					do {
						cout << "Your Option for this Submenu: ";
						cin >> sub_menu2;

						switch (sub_menu2)
						{
						case 1:
							main_menu(main_menu_var);
							break;
						case 2:
							exit(main_menu_var, n, array_main);
							break;
						};
					} while ((sub_menu2 > 2) || (sub_menu2 == 0));

					break;
				}
				case 3:
					main_menu(main_menu_var);
					break;
				case 4:
					exit(main_menu_var);
					break;
				};
			} while ((sub_menu3 > 4) || (sub_menu3 == 0));
			break;
		}
		case 4: // Sort by age in ascending way
		{
			if (n == 0)
			{
				cout << '\n' << "There are currently no enlisted Contenstants!" << '\n';
			}
			else if (n == 1)
			{
				cout << '\n' << "Currently there is only one Contestant enlisted!" << '\n';
			}
			else
			{
				int n_sort;
				n_sort = sizeof(array_main) / sizeof(array_main[0]);
				bubbleSort_age(array_main, n_sort);
				cout << '\n' << "The Array has been successfully Sorted!" << '\n';
			}
			main_menu_var = 0;

			cout << '\n' << "To continue choose an option from the main menu!";
			break;
		}			
		case 5: // Operations with files
		{
			int menu_5;
			system("cls");
			cout << "1. Save the list of participants to a file.\n";
			cout << "2. Read information about the participants from a file.\n";
			do
			{
				cout << '\n' << "Your Choice: ";
				cin >> menu_5;
				switch (menu_5)
				{
					
				case 1:
				{
					outstream.open("Saved_List.dat", ios::out | ios::binary);

					if (outstream.fail())
					{
						cout << "Could not open the file!\n";
						return 0;
					};

					outstream.write((char*)array_main, n * sizeof(array_participants));
					outstream.close();
					break;
				}
				case 2:
				{

					instream.open("Saved_List.dat", ios::in | ios::binary);

					if (instream.fail())
					{
						cout << "Could not open the file!\n";
						return 0;
					}
					int file_size;
					int number_of_elements;
					instream.seekg(0, ios::end);
					file_size = instream.tellg();
					if (file_size / sizeof(array_participants) < n) {
						cout << "\nCaution!\n" << "You are about to lose the last " << n - (file_size / sizeof(array_participants)) << " participant(s) included!\n";
						cout << "To Continue Please choose an option: \n" << "\n";
						cout << "1. Save the current list of participants in a seperate file before continuing\n";
						cout << "2. Continue and lose the last " << n - (file_size / sizeof(array_participants)) << " included.\n";

						unsigned sub_menu_5_2;
						do {
							cout << "\n" << "Your Option: ";
							cin >> sub_menu_5_2;
							switch (sub_menu_5_2)
							{
							case 1:
								outstream.open("Saved_List_Reserved.dat", ios::out | ios::binary);

								if (outstream.fail())
								{
									cout << "Could not open the file!\n";
									return 0;
								};

								outstream.write((char*)array_main, n * sizeof(array_participants));
								outstream.close();

								instream.seekg(0, ios::beg);
								instream.read((char*)&array_main, file_size);
								instream.close();
								n = file_size / sizeof(array_participants);
								cout << n << '\n';
								system("pause");

								array_participants_output(array_main[0]);
								break;
							case 2:
								instream.seekg(0, ios::beg);
								instream.read((char*)&array_main, file_size);
								instream.close();
								n = file_size / sizeof(array_participants);
								cout << n << '\n';
								system("pause");

								array_participants_output(array_main[0]);
								break;
							}
						} while (sub_menu_5_2 == 0 || sub_menu_5_2 > 2);

					}
					else
					{
						instream.seekg(0, ios::beg);
						instream.read((char*)&array_main, file_size);
						instream.close();
						n = file_size / sizeof(array_participants);
					};
					break;
				}
					
				}
			} while ((menu_5 > 2)|| (menu_5 == 0) || (menu_5 < 0));
			navigation(main_menu_var, n, array_main);
		}
			break;
		case 6: // Additional Functions
			sub_menu_6();
			int sub_menu6;

			do {
				cout << "Your Option for this Submenu: ";
				cin >> sub_menu6;

				switch (sub_menu6)
				{
				case 1:
				{
					system("cls");
				
					array_participants sorted_array[N];
					for (int k = 0; k < n; k++)
					{
						sorted_array[k] = array_main[k];
					};
					bubbleSort_name_age(sorted_array, n);
					cout << "The array has been sorted by age and name without alteration in the main array:\n" << '\n';
					for (int k = 0; k < n; k++)
					{
						cout << "Contestant " << (k + 1) << ": \n";
						array_participants_output(sorted_array[k]);

					};

					navigation(main_menu_var, n, array_main);
					break;
				}
				case 2: // Age and Name Search
				{
					system("cls");
					unsigned age_look;
					string sex_look;

					cout << "Gathering information..." << '\n' << '\n';

					cout << "Please input the age and the sex you would like to search for: ";
					cout << "\nAge: ";
					cin >> age_look;
					cout << "Sex: ";
					cin.ignore(1000, '\n');
					getline(cin, sex_look);

					bool sex_check;
					bool rep_check_6_2;
					bool check_of_check_6_2;
					rep_check_6_2 = true;
					check_of_check_6_2 = false;

					for (int i_6_2 = 0; i_6_2 < n; i_6_2++)
					{
						sex_checking(array_main[i_6_2], sex_look, sex_check);
						if (sex_check)
						{
							if (array_main[i_6_2].age == age_look)
							{
								if (rep_check_6_2 == true) cout << '\n' << "We have found a match\n";
								array_participants_output(array_main[i_6_2]);
								check_of_check_6_2 = true;
								rep_check_6_2 = false;
							}
						};
					};

					if (!check_of_check_6_2) cout << "\nUnfortunately there are not participants that match both the given age and sex!\n";
				
					navigation(main_menu_var, n, array_main);
					break;
				}
				case 3:
					main_menu(main_menu_var);
					break;
				case 4:
					exit(main_menu_var, n, array_main);
					break;
				};
			} while ((sub_menu6 > 4) || (sub_menu6 == 0));
			break;
		case 7:
			system("cls");
			if (n == 0)cout << "Please add participants first!";
			else
			{
				if (menu7 == false)
				{

					fill_subarrays(array_main, array14_16, n, n14_16, 13, 17);
					fill_subarrays(array_main, array17_19, n, n17_19, 16, 20);
					fill_subarrays(array_main, array20_22, n, n20_22, 19, 23);
					fill_subarrays(array_main, array23_25, n, n23_25, 22, 26);
					menu7 = true;
				};


				out_subarrays(array14_16, n14_16, 14, 16);
				out_subarrays(array17_19, n17_19, 17, 19);
				out_subarrays(array20_22, n20_22, 20, 22);
				out_subarrays(array23_25, n23_25, 23, 25);
			}

			navigation(main_menu_var, n, array_main);

			break;
		case 8:
			if (n == 0)cout << "Please add participants first!";
			else
			{
				if (menu7 == false)
				{

					fill_subarrays(array_main, array14_16, n, n14_16, 13, 17);
					fill_subarrays(array_main, array17_19, n, n17_19, 16, 20);
					fill_subarrays(array_main, array20_22, n, n20_22, 19, 23);
					fill_subarrays(array_main, array23_25, n, n23_25, 22, 26);
					menu7 = true;
				};
				unsigned sub_menu8;
				system("cls");
				cout << "1. Placements for age category (14 - 16)\n";
				cout << "2. Placements for age category (17 - 19)\n";
				cout << "3. Placements for age category (20 - 22)\n";
				cout << "4. Placements for age category (23 - 25)\n";
				
				do
				{
					cout << "\nYour choice: ";
					cin >> sub_menu8;
					switch(sub_menu8)
					{
					case 1:
						if_function_array(array14_16, winner1, n14_16, 14, 16);
						break;
					case 2:
						if_function_array(array17_19, winner2, n17_19, 17, 19);
						break;
					case 3:
						if_function_array(array20_22, winner3, n20_22, 20, 22);
						break;
					case 4:
						if_function_array(array23_25, winner4, n23_25, 23, 25);
						break;
					}
				

				} while (sub_menu8 > 4 || sub_menu8 == 0);
				
			}
			
			navigation(main_menu_var, n, array_main);

			break;
		case 9:
			exit(main_menu_var, n, array_main);
			break;



		}
	}while ((main_menu_var > 9) || (main_menu_var == 0));




	cout << "End of the Program! (From Main)" << '\n';


	system("pause");
	return 0;

};



/*Functions */
void if_function_array(array_participants arr[], array_participants array[], int sub_n, int age1, int age2)
{
	int i = 0;
	int n = 0;
	for (int i = 0; i < sub_n; i++) {
		if (arr[i].proportion > 0.539 && arr[i].proportion < 0.621)
		{
			array[n] = arr[i];
			n = n + 1;
		};
	}
	cout << "\nWinner of the category (" << age1 << " - " << age2 << "): \n";

	bubbleSort_proportion(array, n);
	for (int i = 0; i < n; i++) {
		cout << "------------------------------------------------" << "\nProportion rating: " << setprecision(3) << array[i].proportion << '\n';
		array_participants_output(array[i]);
	}
	
	array_participants excess1[N];
	int n_ex1;
	n_ex1 = 0;
	for (int i = 0; i < sub_n; i++) {
		if (arr[i].proportion < 0.54)
		{
			excess1[n_ex1] = arr[i];
			n_ex1 = n_ex1 + 1;
		};
	};
	if (n_ex1 == 0) cout << "\nThere are no participants with proportion rating below 0.54!\n" << '\n';
	else
	{
		cout << "\nBelow 0.54 of the category (" << age1 << " - " << age2 << "): \n";
		bubbleSort_proportion(excess1, n_ex1);
		for (int i = 0; i < n_ex1; i++)
		{
			cout << "------------------------------------------------" << "\nProportion rating: " << setprecision(3) << excess1[i].proportion << '\n';
			array_participants_output(excess1[i]);
		};
	}
	array_participants excess2[N];
	int n_ex2;
	n_ex2 = 0;
	for (int i = 0; i < sub_n; i++) {
		if (arr[i].proportion > 0.62)
		{
			excess2[n_ex2] = arr[i];
			n_ex2 = n_ex2 + 1;
		};
	};

	if (n_ex2 == 0) cout << "There are no participants with proportion rating above 0.62\n" << '\n';
	else
	{
		cout << "\nAbove 0.62 of the category (" << age1 << " - " << age2 << "): \n";
		bubbleSort_proportion(excess2, n_ex2);
		for (int i = 0; i < n_ex2; i++)
		{
			cout << "------------------------------------------------" << "\nProportion rating: " << setprecision(3) << excess2[i].proportion << '\n';
			array_participants_output(excess2[i]);
		};
	}

};

void bubbleSort_proportion(array_participants arr[], int n)
{

	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1; j++)
		{
			if (arr[j].proportion > arr[j + 1].proportion) // > is the correct: I can switch for descending or ascending from here (have to change int to unsigned in the struct and vice versa)
				swapping(arr, j);

		};
	};
};

void fill_subarrays(array_participants arr[], array_participants arr_filling[], int n, int& n2, int age1, int age2)
{
	for (int i = 0; i < n; i++)
	{

		if (arr[i].age > age1 && arr[i].age < age2)
		{
			arr_filling[n2] = arr[i];
			n2 = n2 + 1;
		}
	};
};

void out_subarrays(array_participants arr[], int n2, int age1, int age2)
{
	if (n2==0) cout << "\nThere are no participants in the age category between (" << age1 << "-" << age2 << ")!\n";
	else {
		cout << "\nHere is a list of all participants in category (" << age1 << "-" << age2 << "):\n";
		for (int i = 0; i < n2; i++)
		{
			array_participants_output(arr[i]);
		}
	}
};

// Main Menu Function Call
unsigned main_menu(unsigned &m_menu)
{
	system("cls");

	cout << "Welcome to The Program!" << '\n' << '\n' << "Please Choose an Option from Below!" << '\n' << '\n';
	cout << "1. Add a Participant to the list of Contestants." << '\n';
	cout << "2. Receive a list of all Contestants." << '\n';
	cout << "3. Search by Name or Find out the youngest Contestants." << '\n';
	cout << "4. Sort the enlisted Participants by age in an ascending way." << '\n';
	cout << "5. File Operations." << '\n';
	cout << "6. Additional Operations." << '\n';
	cout << "7. Sorting by Categories." << '\n';
	cout << "8. Placements." << '\n';
	cout << "9. Exit The Program." << '\n';
	m_menu = 0;

	return m_menu;

};

void navigation(unsigned& main_menu_var_nav, int n , array_participants arr[])
{
	sub_menu_2();
	int sub_menu2;

	do {
		cout << "Your Option for this Submenu: ";
		cin >> sub_menu2;

		switch (sub_menu2)
		{
		case 1:
			main_menu(main_menu_var_nav);
			break;
		case 2:
			exit(main_menu_var_nav, n , arr);
			break;
		};
	} while ((sub_menu2 > 2) || (sub_menu2 == 0));
};

// 1. First Submenu Associated Function Calls
void sub_menu_1()
{
	system("cls");

	cout << "To Continue Please Choose an Option from Below: " << '\n' << '\n';
	cout << "1. Add a new contestant." << '\n';
	cout << "2. Return to the Main Menu." << '\n';
	cout << "3. Exit the Program." << '\n' << '\n';
};
void sub_menu_1_1(int& n_n, int& i_i, int j_j, array_participants array_main_m1[])
{
	system("cls");
	cout << "In the Process of Adding a New Participant..." << "\n" << "\n";
	cout << "Enter the Number of Participants to be added: ";
	cin >> n_n;

	if (i_i + n_n > N)
	{
		do {
			cout << '\n' << "You have exceeded the number of possible constenstants that can be included. Please input a smaller number: ";
			cin >> n_n;
		} while (i_i + n_n > N);
	}
	j_j = i_i;

	for (i_i; i_i < (n_n + j_j); i_i++)
	{
		array_main_m1[i_i] = input();
	}
	if (n_n > 0) {
		congratz_1();
	};

	n_n = i_i;
	sub_menu_1();
};


//2. Second Submenu Associated Function Calls - Output --------------------------------------------------- Needs work
void sub_menu_2()
{
	cout << '\n';

	cout << "To Continue Please Choose an Option from Below: " << '\n' << '\n';
	cout << "1. Return to the Main Menu." << '\n';
	cout << "2. Exit the Program." << '\n' << '\n';
};
void array_participants_output(array_participants array_a)
{
	cout << '\n' << "Name: " << array_a.name;
	cout << '\n' << "Age: " << array_a.age;
	cout << '\n' << "Sex: " << array_a.sex;
	cout << '\n' << "Measurements: ";
	cout << '\n' << "Hip: " << array_a.hip_circ;
	cout << '\n' << "Shoulder: " << array_a.shoulder_circ;
	cout << '\n' << "Neck: " << array_a.neck_circ;
	cout << '\n' << "Calf: " << array_a.calf_circ;
	cout << '\n' << "Serial Number: " << array_a.serial_number << '\n';
	cout << "--------------------------------------------" << "\n";
};


//3. Third Submenu
void sub_menu_3()
{
	system("cls");

	cout << "To Continue Please Choose an Option from Below: " << '\n' << '\n';
	cout << "1. Search a Contestant by Name." << '\n';
	cout << "2. Find out the youngest participant(s)." << '\n';
	cout << "3. Return to the Main Menu." << '\n';
	cout << "4. Exit the Program." << '\n' << '\n';
};
void name_checking(array_participants name_arr, string name_look_f, bool& name_check)
{
	if (name_arr.name == name_look_f)
	{
		name_check = true;
	}
	else name_check = false;
};

void sex_checking(array_participants name_arr, string sex_look_f, bool& sex_check)
{
	if (name_arr.sex == sex_look_f)
	{
		sex_check = true;
	}
	else sex_check = false;
};

void sub_menu_3_1()
{
	cout << '\n' << "Would you like to continue searching with another name?" << "\n" << '\n';
	cout << "1. Yes." << '\n';
	cout << "2. No." << '\n';
}
void sub_menu_yes_or_no(string name_look_yes_or_no)
{
	cout << '\n' << "Unfortunately, there are no contestants that match the name " << name_look_yes_or_no << '\n' << '\n';
	cout << "Would you like to continue searching with another name?" << "\n" << '\n';
	cout << "1. Yes." << '\n';
	cout << "2. No." << '\n';
};
void name_update(string& name_update) 
{
	cout << "Gathering information(...)" << '\n' << '\n';
	cout << "Please input the name of the person you are looking for: ";
	cin.ignore(1000, '\n');
	getline(cin, name_update);
};
void searching_by_name_f(array_participants name_arr_repeat, string &name_look_subf, bool& name_check_repeat, bool &double_check_f)
{
	
	if (name_arr_repeat.name == name_look_subf)
	{
		array_participants_output(name_arr_repeat);
		name_check_repeat = true;
		double_check_f = true;
	}
	else
	{
		name_check_repeat = false;
	}


};
void min_agef(array_participants min_age_var, unsigned& min_age)
{
	if (min_age > min_age_var.age) min_age = min_age_var.age;
};
void youngest(array_participants youngest_people, int i_3_2_f, unsigned min_age_f)
{

	if (youngest_people.age == min_age_f)
	{
		cout << '\n' << "Contestant " << (i_3_2_f + 1) << '\n';
		array_participants_output(youngest_people);
	};
};


//6. Sixth Submenu
void sub_menu_6()
{
	system("cls");
	cout << "To Continue Please Choose an Option from Below: " << '\n' << '\n';
	cout << "1. Preview the List of Contestants sorted by Name and Age." << '\n';
	cout << "2. Search in the List of Contestants by Name and Age" << '\n';
	cout << "3. Return to the Main Menu." << '\n';
	cout << "4. Exit the Program." << '\n' << '\n';
}

// Input Function for the struct array
array_participants input()
{
	array_participants p;

	cin.ignore(1000, '\n');
	cout << "\n" << "Input the Serial Number of the participant: ";

	getline(cin, p.serial_number);

	cout << "Input their Name: ";
	getline(cin, p.name);

	cout << "Input their Age (14 - 40): ";
	cin >> p.age;
	if ((p.age < 14) || (p.age > 40))
	{
		do {
			cout << "The Contestant's age must be within the permitted age group for all Participants." << '\n';
			cout << "Input their Age (14 - 40): ";
			cin >> p.age;

		} while ((p.age < 14) || (p.age > 40));
	};

	cin.ignore(1000, '\n');
	cout << "Input their Sex: ";
	getline(cin, p.sex);


	cout << "Input the Measurements for their: " << '\n' << "Hip: ";
	cin >> p.hip_circ;
	if ((p.hip_circ < 80) || (p.hip_circ > 130))
	{
		do {
			cout << "It seems the contestant will be a poor match for this particular competition" << '\n';
			cout << "Correct their measurement (80 - 130): ";
			cin >> p.hip_circ;

		} while ((p.hip_circ < 80) || (p.hip_circ > 130));
	};

	cout << "Shoulder: ";
	cin >> p.shoulder_circ;
	if ((p.shoulder_circ < 30) || (p.shoulder_circ > 90))
	{
		do {
			cout << "It seems the contestant will be a poor match for this particular competition" << '\n';
			cout << "Correct their measurement (30 - 90): ";
			cin >> p.shoulder_circ;

		} while ((p.shoulder_circ < 30) || (p.shoulder_circ > 90));
	};

	cout << "Neck: ";
	cin >> p.neck_circ;
	if ((p.neck_circ < 20) || (p.neck_circ > 50))
	{
		do {
			cout << "It seems the contestant will be a poor match for this particular competition" << '\n';
			cout << "Correct their measurement (20 - 50): ";
			cin >> p.neck_circ;

		} while ((p.neck_circ < 20) || (p.neck_circ > 50));
	};

	cout << "Calf: ";
	cin >> p.calf_circ;
	if ((p.calf_circ < 20) || (p.calf_circ > 60))
	{
		do {
			cout << "It seems the contestant will be a poor match for this particular competition" << '\n';
			cout << "Correct their measurement (20 - 60): ";
			cin >> p.calf_circ;

		} while ((p.calf_circ < 20) || (p.calf_circ > 60));
	};

	p.proportion = p.hip_circ/(p.shoulder_circ + p.neck_circ + p.calf_circ);

	/*if ((proportion_check < 0.3) || (proportion_check > 2.0))
	{
		do {
			cout << "We are afraid that your Contesntant cannot Participate in our Beauty Competition with such Body Proportions" << '\n';
			cout << "Try Correcting your Measuremnts!" << '\n';
			cout << "Input the Measurements for their: " << '\n' << "Hip: ";
			cin >> p.hip_circ;
			cout << "Shoulder: ";
			cin >> p.shoulder_circ;
			cout << "Neck: ";
			cin >> p.neck_circ;
			cout << "Calf: ";
			cin >> p.calf_circ;

			proportion_check = p.hip_circ / (p.shoulder_circ + p.neck_circ + p.calf_circ);
			cout << proportion_check << '\n';

		} while ((proportion_check < 0.3) || (proportion_check > 2.0));
	}*/
	return p;
};





/* Text Function Calls*/
void congratz_1()
{
	cout << '\n' << "You have successfully added the participant(s) to the list of contestants!" << '\n' << '\n';
	system("pause");
};

//9. Ninth Exit Function Call
void exit(unsigned &main_menu_var_exit, int n, array_participants arr[])
{
	system("cls");
	fstream outstream;
	cout << "Thank you for using my Program for Beauty Competition!" << '\n';
	int end;
	cout << '\n' << "Type \"0\" to confirm you want to Exit or any other number to return the Main Menu: ";
	cin >> end;
	if (!end)
	{
		outstream.open("Saved_List.dat", ios::out | ios::binary);

		if (outstream.fail())
		{
			cout << "Could not open the file!\n";
			system("puase");
			exit(0);
		};

		outstream.write((char*)arr, n * sizeof(array_participants));
		outstream.close();
		cout << '\n' << "This is the of End of the Program!" << '\n';
		system("pause");

		exit(0);
	}
	else {
		cout << '\n' << "Thank you for sticking around! " << '\n' << "Please note that your input has been saved. " << '\n';
		cout << '\n' << "You will now be redirected to the Main Menu!" << '\n';
		system("pause");
		main_menu(main_menu_var_exit);

	};
};



/* Sort functions */


void bubbleSort_age(array_participants arr[], int n)
{
	
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1; j++)
		{
			if (arr[j].age > arr[j + 1].age) // I can switch for descending or ascending from here (have to change int to unsigned in the struct and vice versa)
				swapping(arr, j);

		};
	};
};

void bubbleSort_name_age(array_participants arr[], int n)
{
	int i, j, k;
	k = 10;
	for (i = 0; i < n - 1; i++) {

		// Last i elements are already
		// in place
		for (j = 0; j < n - 1; j++)
		{
			if (arr[j].age > arr[j + 1].age) {
				swapping(arr, j);
			};
		};
		for (j = 0; j < n - 1; j++)
		{
			if (arr[j].age == arr[j + 1].age)
			{
				if (arr[j].name < arr[j + 1].name)
				{
					k = 1;
				}
				else if (arr[j].name == arr[j + 1].name) { k = 0; }
				else k = -1;
				if (k == -1) // If k == 1 -> Descending alphabetical order CBA, If k== -1 -> Ascending alphabetical order ABC
				{
					swapping(arr, j);
					k = 10;
				}
				else if (k == 0)
				{
					cout << "\n Both names are the same!\n";
					k = 10;
				}
				else k = 10;
			}
		}


	}
};
void swapping(array_participants arr[], int l)
{
	array_participants buf;
	buf = arr[l];
	arr[l] = arr[l + 1];
	arr[l + 1] = buf;
};

/* Quick sort

int partition(array_participants arr[], int low, int high)
{
	unsigned pivot = arr[high].age;
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j].age < pivot)
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
};

void quickSort(array_participants arr[], int low, int high)
{
	if (low < high) {
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	};
};

*/