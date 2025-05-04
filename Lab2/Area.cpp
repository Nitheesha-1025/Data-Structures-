#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
class area{
  private:
         int length,breadth,height;

   public:
         void Square()
         {
            int area_square=length*length;
            cout<<"Area of the square\n";
            cout<<area_square<<"\n";
         }

         void cube()
         {
            int area_cube=length*length*length;
            cout<<"Area of the cube\n";
            cout<<area_cube<<"\n";
         }

         void rectangle()
         {
            int area_rec=length*breadth;
            cout<<"Area of the rectangle\n";
            cout<<area_rec<<"\n";
         }
         void cuboid()
         {
            int area_cuboid=length*breadth*height;
            cout<<"Area of the cuboid\n";
            cout<<area_cuboid<<"\n";
         }

         void setter(int length1,int breadth1,int height1)
         {
            length=length1;
            breadth=breadth1;
            height=height1;
         }

         
      
      
      
      
};

int main()
{
    int opt;
    area shape;


    while(1){
    cout<<"Enter the choice you want to make\n1.Square\n2.Cube\n3.Rectangle\n4.Cuboid\n5.exit\n";
    cin>>(opt);
    cout<<"\n";
    
    
    
    switch(opt)
    {
        case 1:
                int side;
                cout<<"Enter the side \n";
                cin>>side;
                shape.setter(side,0,0);
                shape.Square(); 
                break;
        case 2:
                 int side_cube;
                cout<<"Enter the side \n";
                cin>>side_cube;
                shape.setter(side_cube,0,0);
                shape.cube();
                break;
        case 3:
                int len,bread;
                cout<<"Enter the lenght\n";
                cin>>len;
                cout<<"Enter the breadth\n";
                cin>>bread;
                shape.setter(len,bread,0);
                shape.rectangle();
                break;
        case 4:
                int len_cuboid,bread_cuboid,hei_cuboid;
                cout<<"Enter the length\n";
                cin>>len_cuboid;
                cout<<"Enter the breadth \n";
                cin>>bread_cuboid;
                cout<<"Enter the height\n";
                cin>>hei_cuboid;
                shape.setter(len_cuboid,bread_cuboid,hei_cuboid);
                shape.cuboid();
                
        case 5:
                printf("exit\n");
                return 0;       
        default:
                 printf("Invalid Option\n");
                
    }
    }
}