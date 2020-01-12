/**********|**********|**********|
Program: TT02_A1_GHYASI_SHOAIB.cpp / YOUR_FILENAME.h 
Course: Data Structures and Algorithms
Year: 2019/2020 Trimester 2
Name: GHYASI SHOAIB
ID: 1151300052
Lecture Section: TC101
Tutorial Section: TT02
Email: GHYASISHOAIB@GMAIL.COM
Phone: 017-4642469
**********|**********|**********/

#include <iostream>
#include <sstream>
#include <windows.h>
#include <vector>
#include <fstream>
#include <ctime>
#include <stdlib.h>

using namespace std;

// a parent class that has the common attributes and behaviours among different shapes
class Shape{
    
    public:
   
    // Checks if this whole shape can be placed within the area.
    virtual bool checkRange(vector<vector<char>> area, int rand_x, int rand_y) = 0;
    
    
    // Checks if this whole shape can be placed in empty units in the area.
    virtual bool checkArea(vector<vector<char>> area, int rand_x, int rand_y) = 0;
    
    
    // places this shape in the area if all units are empty.
	virtual void placement(vector<vector<char>>& area, int rand_x, int rand_y, char shape_marker) = 0;
	
    // Displays the discription of this shpae including the type of the shape and 
    // the lenght and the width of the shape
    virtual void discription() = 0;
};


// a child class represents a shape of type Triangle that inherents from Shape class.
class Triangle : public Shape{
    
    private:
    
    int height;		// the height of the Triangle.
    
    public:
    
    
    // Constructor of the Triangle class.
    Triangle(int height){

        this->height = height;

    }
    
    bool checkRange(vector<vector<char>> area, int rand_x, int rand_y){
        
        // if else statement to check if triangle can fit with in the area.
        if(rand_x - (height-1) >= 0 && rand_x + (height-1) < area[0].size() && rand_y + (height-1) < area.size()){
            return true;
        }
        else{
            return false;
        }
    }
    
    bool checkArea(vector<vector<char>> area, int rand_x, int rand_y){
        
        for(int y = 0; y < height; y++){
            for(int x = rand_x - y ; x <= rand_x + y; x++){
            	if(area[rand_y + y][x] != '.')
              		// return false and stop placing remaining units if any unit is not empty.
                	return false;
            }
        }

        // return true after whole units of this triangle is successfully can be placed in the area.
        return true;
    }

    void placement(vector<vector<char>>& area, int rand_x, int rand_y, char shape_marker){
    	for(int y = 0; y < height; y++){
            for(int x = rand_x - y ; x <= rand_x + y; x++){
            	area[rand_y + y][x] = shape_marker;
            }
        }
    }

    void discription(){

    	cout<< "  This shape is a Triangle with height of " << height << " unit(S)"; 
    }
    
};

// a child class represents a shape of type Rectangle that inherents from Shape class.
class Rectangular : public Shape{
    
    private:
    
    int length;		// the length of the Rectangle.
    int width;		// the width of the Rectangle.
    
    public:
    
    
    // Constructor of the Rectangle class.
    Rectangular(int length, int width){

        this->length = length;
        this->width = width;
    }
    
    bool checkRange(vector<vector<char>> area, int rand_x, int rand_y){
        
        // if else statement to check if rectangle can fit with in the  area.
        if(rand_x + (width-1) < area[0].size() && rand_y + (length-1) < area.size()){
            return true;
        }
        else{
            return false;
        }
    }
    
    bool checkArea(vector<vector<char>> area, int rand_x, int rand_y){
        
        for(int y = rand_y; y < rand_y + length; y++){
            for(int x = rand_x; x < rand_x + width; x++){
          		if(area[y][x] != '.')
              		// return false and stop checking remaining units if any unit of the area is not empty.
              		return false;
            }
        }

        // return true after whole units of this rectangle is successfully checked and can be placed in the area.        
        return true;
    }

    void placement(vector<vector<char>>& area, int rand_x, int rand_y, char shape_marker){
    	for(int y = rand_y; y < rand_y + length; y++){
            for(int x = rand_x; x < rand_x + width; x++){
          		area[y][x] = shape_marker;
            }
        }
    }

    void discription(){

    	cout<< "  This shape is a Rectangle with length of " << length << " unit(S) and width of " << width << " units(S)"; 
    }
    
};

// a child class represents a shape of type Square that inherents from Shape class.
class Square : public Shape{
    
    private:
    
    int length; // the length and the width of the Square which are similar.
    
    public:
    

    // Constructor of the Square class.
    Square(int length){

        this->length = length;
    }
    
    bool checkRange(vector<vector<char>> area, int rand_x, int rand_y){
        
        // if else statement to check if square can fit with in the area.
        if(rand_x + (length-1) <  area[0].size() && rand_y + (length-1) < area.size()){
            return true;
        }
        else{
            return false;
        }
    }
    
    bool checkArea(vector<vector<char>> area, int rand_x, int rand_y){
                
        for(int y = rand_y; y < rand_y + length; y++){
	        for(int x = rand_x; x < rand_x + length; x++){
          		if(area[y][x] != '.')
              		// return false and stop checking remaining units if any unit of the area is not empty.
              		return false;
	        }
        }
        // return true after whole units of this rectangle is successfully checked and can be placed in the area.
        return true;
    }

    void placement(vector<vector<char>>& area, int rand_x, int rand_y, char shape_marker){

    	for(int y = rand_y; y < rand_y + length; y++){
	        for(int x = rand_x; x < rand_x + length; x++){
	          	area[y][x] = shape_marker;
	        }
        }
    }

    void discription(){

    	cout<< "  This shape is a Square with length of " << length << " unit(S) and width of " << length << " units(S)"; 
    }
    
};

void displayArea(vector<vector<char>> area){
	for(int y = 0; y < area.size(); y++){
	    for(int x = 0; x < area[y].size(); x++){
	        cout<<area[y][x]<<" ";
	    }
	    cout<<endl;
    }
}

// save area contents after failed or successful attemp.
void saveArea(vector<vector<char>> area, string fileName){

   ofstream output_file(fileName);

   output_file << "  " << fileName << endl << endl;

   for(int y = 0; y < area.size(); y++){
	  
	  for(int x = 0; x < area[0].size(); x++){
		output_file << area[y][x];
	  }
	  
	  output_file << endl;
	}

	output_file.close();
}

int main()
{
   int attemps;		// number of attemps to be used to place the shapes.
   int shapesNo;	// total number of shapes to be placed in the  area.
   int area_height, area_width;		// length and width of area.
   		
	ifstream input_file("Batch.txt");

	// error message and exit program if input file cannot be opened.
	if(!input_file.is_open()){
		cout << endl <<endl << "Unable to find Batch.txt file"<<endl <<endl;
		system("pause");
		return 0;
	}

	// read area lenght and width, number of attemps and number of shapes from input file.
    input_file >> area_height >> area_width >> attemps;

    input_file >> shapesNo;

    Shape* shapes[shapesNo];

    char indicator_char;	// indicates type of shape to construct.
	
	for(int i=0; i<shapesNo && !input_file.eof(); i++){
		
		input_file >> indicator_char;	// read shape indicator

		// input shape based on shape indicator.
		switch(indicator_char){

			case 's':{
				// input square
				int length;
				input_file >> length;
				Square* square = new Square(length);
				shapes[i] = square;
				break;
			}

			case 'r':{
				// input rectangle
				int length, width;
				input_file >> length >> width;
				Rectangular* rectangle = new Rectangular(length, width);
				shapes[i] = rectangle;
				break;
			}

			case 't':{
				// input triangle
				int height;
				input_file >> height;
				Triangle* triangle = new Triangle(height);
				shapes[i] = triangle;
				break;
			}

			default:
				cout << endl <<endl << "Error while reading shapes from Batch.txt file"<<endl <<endl;
	   			system("pause");
	   			break;			
		}
	}	

    input_file.close();

    char marker[26] = {'A','B','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

    // repeat attemps to successfully place all shapes until all attemps are used. 
    for(int attemp = 1; attemp <= attemps; attemp++){

   	   bool success = false;
   	  
		stringstream ss;
		ss << attemp;
		string str_attemp = ss.str();
    
   	   system("cls");
   	   cout<<endl<<endl;
	   cout<< "  attemp "<<attemp<<" out of "<<attemps<<endl<<endl;
	   cout<<endl;

	   vector<vector<char>> area;
	   
	    for(int y = 0; y < area_height; y++){
          vector<char> temp;
          
          for(int x = 0; x < area_width; x++){
             temp.push_back('.');
          }          
          area.push_back(temp);
        }

   	   displayArea(area);

   	   cout<<endl<<endl;
   	   system("pause");

	   for(int i = 0; i < shapesNo; i++){
		   
		   int rand_x, rand_y;

		    srand(time(NULL));
		    rand_x = (rand() %area_width) + 1;
		    rand_y = (rand() %area_height) + 1;

			cout<<endl<<endl;
			shapes[i]->discription();
			cout<<endl<< "  Trying to place this shape in (" << rand_x << ", " << rand_y <<")"<<endl<<endl;
			system("pause");
			cout<<endl;

		   if(shapes[i]->checkRange(area, rand_x-1, rand_y-1)){
		   		if(shapes[i]->checkArea(area, rand_x-1, rand_y-1)){
		   			shapes[i]->placement(area, rand_x-1, rand_y-1, marker[i]);
		   		}
		   		else{
			   		cout<<endl<<endl;
					cout<< "  Failed attemp: unable to place the shape. occupied unit found!"<<endl<<endl;
					cout<<endl;
					string fileName = "Failed.";fileName+=str_attemp;fileName+=".txt";
					saveArea(area, fileName);
					system("pause");
					break;
			   	}
			   
		   }
		   else{
		   		cout<<endl<<endl;
				cout<< "  Failed attemp: shape exceeds area range!"<<endl<<endl;
				cout<<endl;
				string fileName = "Failed.";fileName+=str_attemp;fileName+=".txt";
				saveArea(area, fileName);
				system("pause");
				break;
		   }
		   
		   // if all shapes are placed successfully this if statement will evaluate to True.
		   if(i == shapesNo-1){
		   		cout<<endl<<endl;
				cout<< "  Good job you are lucky this time: your attemp is successful!"<<endl<<endl;
				string fileName = "successfull.";fileName+=str_attemp;fileName+=".txt";
			    saveArea(area, fileName);
			    system("pause");
				success = true;
		   }
		   displayArea(area);
		   
		}

		// stop attemping if all shapes are successfully placed in baord area.
		if(success)
			break;

		if(attemp == attemps){
			system("cls");
	   		cout<<endl<<endl;
			cout<< "  No more available attemps. Good luck next time!"<<endl<<endl;
		    cout<<endl<<endl;
		    displayArea(area);
	   }
	}
   
   return 0;
}