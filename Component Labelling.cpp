#include<iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
using namespace cv;
using namespace std;

class indexes
{
public:
	int starting_1s, ending_1s,flag ;
	indexes* next;

	indexes()
	{
		flag = 0;
		starting_1s = 0;
		ending_1s = 0;
		next = NULL;
	}
};

class driver_class
{
private:

	indexes* start=NULL;

public:

	void task1()
	{
		Mat img, dst;
		img = imread("C:/Users/SOULREAPER/Desktop/Segmented Outputs/mIMD017.bmp");
		img.convertTo(dst, CV_32F);
		float** example = new float* [dst.rows];


		float conflict[10000];
		float equal[10000];

		
		for (int i = 0; i < dst.rows; i++) {

			example[i] = new float[dst.cols];
		}

		for (int i = 0; i < dst.rows; ++i)
		{
			for (int j = 0; j < dst.cols; ++j)
			{
				example[i][j] = dst.at<float>(i, j);
			}

		}

		for (int i = 0; i < dst.rows; ++i)
		{
			for (int j = 0; j < dst.cols; ++j)
			{
				if (example[i][j] == 255)
				{
					example[i][j] = 1;
				}
			}

		}



		int left = 0;
		int top = 0;
		int label = 1;
		int maxCom = 0;
		int Comno = 0;
		int iterator = 0;

		for (int i = 0; i < dst.rows; ++i)
		{
			for (int j = 0; j < dst.cols; ++j)
			{
				if (example[i][j] == 1)
				{
					if (j > 0 && example[i][j - 1] != 0)
					{
						left = example[i][j - 1];

					}

					if (i > 0 && example[i - 1][j] != 0)
					{
						top = example[i - 1][j];

					}

					if (top == 0 && left == 0)
					{
						example[i][j] = label;
						label++;

					}
					else if (top == 0)
					{
						example[i][j] = left;
					}
					else if (left == 0)
					{
						example[i][j] = top;
					}
					else if (top != 0 && left != 0 && top == left)
					{
						example[i][j] = top;
					}
					else if (top != 0 && left != 0 && top != left)
					{
						if (top < left)
						{
							example[i][j] = top;
							conflict[iterator] = left;
							equal[iterator] = top;
							iterator++;

						}
						else
						{
							example[i][j] = left;
							conflict[iterator] = top;
							equal[iterator] = left;
							iterator++;
						}
					}

					top = 0;
					left = 0;
				}
			}

		}

		iterator = 0;
		while (conflict[iterator] != 0)
		{

			for (int i = 0; i < dst.rows; ++i)
			{
				for (int j = 0; j < dst.cols; ++j)
				{
					if (conflict[iterator] == example[i][j])
					{
						example[i][j] = equal[iterator];
					}
				}

			}

			iterator++;
		}


		int num = 0;
		for (int k = 1; k < label; k++)
		{
			for (int i = 0; i < dst.rows; ++i)
			{
				for (int j = 0; j < dst.cols; ++j)
				{
					if (k == example[i][j])
					{
						num++;
					}
				}

			}

			if (maxCom < num)
			{
				maxCom = num;
				Comno = k;
			}

			num = 0;
		}

		cout << maxCom << " " << Comno;

		

	}

	void task3()
	{
		Mat img, dst,img2,dst2;
		img = imread("C:/Users/SOULREAPER/Desktop/Segmented Outputs/mIMD017.bmp");
		img.convertTo(dst, CV_32F);
		float** example = new float* [dst.rows];


		img2 = imread("C:/Users/SOULREAPER/Desktop/Ground Truths/IMD017_lesion.bmp");
		img2.convertTo(dst2, CV_32F);
		float** arr = new float* [dst2.rows];

		for (int i = 0; i < dst2.rows; i++) {

			arr[i] = new float[dst2.cols];
		}

		for (int i = 0; i < dst2.rows; ++i)
		{
			for (int j = 0; j < dst2.cols; ++j)
			{
				arr[i][j] = dst2.at<float>(i, j);
			}

		}

		for (int i = 0; i < dst2.rows; ++i)
		{
			for (int j = 0; j < dst2.cols; ++j)
			{
				if (arr[i][j] == 255)
				{
					arr[i][j] = 1;
				}
			}

		}

		float conflict[10000];
		float equal[10000];

		
		for (int i = 0; i < dst.rows; i++) {

			example[i] = new float[dst.cols];
		}

		for (int i = 0; i < dst.rows; ++i)
		{
			for (int j = 0; j < dst.cols; ++j)
			{
				example[i][j] = dst.at<float>(i, j);
			}

		}

		for (int i = 0; i < dst.rows; ++i)
		{
			for (int j = 0; j < dst.cols; ++j)
			{
				if (example[i][j] == 255)
				{
					example[i][j] = 1;
				}
			}

		}



		int left = 0;
		int top = 0;
		int label = 1;
		int maxCom = 0;
		int Comno = 0;
		int iterator = 0;

		for (int i = 0; i < dst.rows; ++i)
		{
			for (int j = 0; j < dst.cols; ++j)
			{
				if (example[i][j] == 1)
				{
					if (j > 0 && example[i][j - 1] != 0)
					{
						left = example[i][j - 1];

					}

					if (i > 0 && example[i - 1][j] != 0)
					{
						top = example[i - 1][j];

					}

					if (top == 0 && left == 0)
					{
						example[i][j] = label;
						label++;

					}
					else if (top == 0)
					{
						example[i][j] = left;
					}
					else if (left == 0)
					{
						example[i][j] = top;
					}
					else if (top != 0 && left != 0 && top == left)
					{
						example[i][j] = top;
					}
					else if (top != 0 && left != 0 && top != left)
					{
						if (top < left)
						{
							example[i][j] = top;
							conflict[iterator] = left;
							equal[iterator] = top;
							iterator++;

						}
						else
						{
							example[i][j] = left;
							conflict[iterator] = top;
							equal[iterator] = left;
							iterator++;
						}
					}

					top = 0;
					left = 0;
				}
			}

		}

		iterator = 0;
		while (conflict[iterator] != 0)
		{

			for (int i = 0; i < dst.rows; ++i)
			{
				for (int j = 0; j < dst.cols; ++j)
				{
					if (conflict[iterator] == example[i][j])
					{
						example[i][j] = equal[iterator];
					}
				}

			}

			iterator++;
		}


		int num = 0;
		for (int k = 1; k < label; k++)
		{
			for (int i = 0; i < dst.rows; ++i)
			{
				for (int j = 0; j < dst.cols; ++j)
				{
					if (k == example[i][j])
					{
						num++;
					}
				}

			}

			if (maxCom < num)
			{
				maxCom = num;
				Comno = k;
			}

			num = 0;
		}

		//cout << maxCom << " " << Comno;

		double counter1=0;
		double counter2 = 0;
		double counter3 = 0;
		for (int i = 0; i < dst.rows; i++)
		{
			for (int j = 0; j < dst.cols; j++)
			{
				if (arr[i][j] == 1 and example[i][j] == Comno)
				{
					counter1++;
				}
				else if (arr[i][j] == 0 and example[i][j] == Comno)
				{
					counter2++;
				}
				else if (arr[i][j] == 1 and example[i][j] != Comno)
				{
					counter3++;
				}
			}
		}

		double result;
		counter1 = counter1 * 2;
		result = counter1 / (counter2 + counter1 + counter3);
		cout << "DICE : " << result;


	}














	void task4()
	{
		int test[8][8];
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				test[i][j] = 0;
			}
		}

		Mat img, dst;
		img = imread("C:/Users/SOULREAPER/Desktop/Segmented Outputs/mIMD017.bmp");
		img.convertTo(dst, CV_32F);
		float** arr = new float* [dst.rows];

		for (int i = 0; i < dst.rows; i++) {

			// Declare a memory block
			// of size n
			arr[i] = new float[dst.cols];
		}

		for (int i = 0; i < dst.rows; ++i)
		{
			for (int j = 0; j < dst.cols; ++j)
			{
				arr[i][j] = dst.at<float>(i, j);
			}

		}

		for (int i = 0; i < dst.rows; ++i)
		{
			for (int j = 0; j < dst.cols; ++j)
			{
				if (arr[i][j] == 255)
				{

					arr[i][j] = 1;
				}
			}

		}



		
		float col_size = dst.cols, row_size = dst.rows,start_in=-1,end_in=-1;

		for (int iterator_r = 0; iterator_r < row_size; iterator_r++)
		{
			for (int iterator_c = 0; iterator_c < col_size; iterator_c++)
			{
				//cout << iterator_c << endl;
				
				if (arr[iterator_r][iterator_c] == 1)
				{
					if (start_in == -1)
					{
						start_in = iterator_c;

						//cout << iterator_c;
					}
					
					if (iterator_c < col_size - 1 and arr[iterator_r][iterator_c + 1] == 0)
					{
						end_in = iterator_c;
					    //cout << " "<<iterator_c << endl;
					}

					
					
				}

				if (start_in != -1 && end_in == -1 and iterator_c == col_size - 1)
				{
					indexes* index = new indexes();

					index->flag = 0;
					index->starting_1s = start_in;
					index->ending_1s = iterator_c;


					if (start == NULL)
					{
						start = index;
					}
					else
					{
						indexes* node;
						node = start;
						while (node->next != NULL)
						{
							node = node->next;
						}
						node->next = index;
					}
					end_in = -1;
					start_in = -1;
				}

				if (start_in != -1 && end_in != -1)
				{
					indexes* index = new indexes();
					
						index->flag = 0;
						index->starting_1s = start_in;
						index->ending_1s = end_in;


						if (start == NULL)
						{
							start = index;
						}
						else
						{
							indexes* node;
							node = start;
							while (node->next != NULL)
							{
								node = node->next;
							}
							node->next = index;
						}
						end_in = -1;
						start_in = -1;
				
				}
				
				
			}
			//cout << endl;

			indexes* index = new indexes();//inserting -1

			index->flag = -1;
			index->starting_1s = 0;
			index->ending_1s = 0;

			if (start == NULL)
			{
				start = index;
			}
			else
			{
				indexes* node;
				node = start;
				while (node->next != NULL)
				{
					node = node->next;
				}
				node->next = index;
			}
			end_in = -1;
			start_in = -1;



		}

		
		indexes* node;
		node = start;
		while (node->next != NULL)
		{
			if (node->flag == -1)
			{
				cout << endl;
			}
			else
			{
				cout<<node->starting_1s <<"  "<< node->ending_1s<<" ";
			}
			node = node->next;
		}

		cout << endl << endl;
		node = start;
		int row = 0;
		int column = 0;
		while (node != NULL)
		{
			if (node->flag == -1)
			{
				row++;
				node = node->next;
			}
			else
			{
				for (int i = node->starting_1s; i <= node->ending_1s; i++)
				{
					if (arr[row][i] == 1)
					{
						//cout << "correct" << endl;
					}
					else
					{
						cout << "invalid" << endl;;
					}
				}
				node = node->next;

			}
		}

		//for (int i = 0; i < 8; i++)
		//{
			//for (int j = 0; j < 8; j++)
			//{
				//cout << test[i][j]<<" ";
			//}
			//cout << endl;
		//}


	}
};


int main()
{
	int user_choice = 0;
	cout << "WELCOME TO IMAGE PROCESSOR" << endl;
	cout << "TASK 1 ---> 1" << endl;
	cout << "Task 3 ---> 3" << endl;
	cout << "Task 4 ---> 4" << endl;
	cin >> user_choice;
	driver_class d;
	if (user_choice == 1)
	{
		d.task1();
	}
	else if(user_choice == 3)
	{
		d.task3();
	}
	else if (user_choice == 4)
	{
		
		d.task4();
	}
	


	
}