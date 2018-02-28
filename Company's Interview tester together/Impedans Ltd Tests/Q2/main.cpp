#include <iostream>
#include <string>
#include <sstream>
#include  <vector>
#include <queue>
#include <list>
#include <stdlib.h>
using namespace std;

 class Data_Store{
     public:
        string Com;
        string  Type;
        int     Price;
        int     Quantity;
        string  ID;
};

//class Data_Store Datalist[1000];
int Datanum = 0;

typedef class Operations ClassOper;
typedef list <class Data_Store>  LIST_OPER;

LIST_OPER Oper_List;
class Operations{
    public:

   // Operations();
    Operations(string com,string type,int price, int quantity,string id){
        //Order = order;
        Com = com;
        Type = type;
        Price = price;
        Quantity = quantity;
        ID = id;
    }
    void Match_com(vector <string> operating_string);
    void Print_elemets(void);
    void Oper_Buy_Sell(vector <string> operating_string);
    void value_data(struct Data_Store * data_value,  string com,string type,int price, int quantity,string id);
    void Trade(struct Data_Store Order_first, int quantity1, struct Data_Store Order_second,int quantity2);
    public:
        //int Order;
        string Com;
        string  Type;
        int     Price;
        int     Quantity;
        string  ID;
};
void Operations::Print_elemets(void)
{
    cout<<Com<<" "<<Type<<" "<<Price<<" "<<Quantity<<" "<<ID<<endl;
}


void Operations::Match_com(vector <string> operating_string){
    if(operating_string.size() == 0)
        cout<<"input wrong"<<endl;

    string COM =  operating_string[0];

    if(!COM.compare("BUY") || !COM.compare("SELL"))
    {
        Oper_Buy_Sell(operating_string);
    }
    else if(!COM.compare( "CANCEL")){

    }
    else if(!COM.compare("MODIFY")){

    }
    else if (!COM.compare("PRINT")){

    }
    else{
            cout<<"input wrong"<<endl;
    }
}

void Operations::value_data(struct Data_Store * data_value, string com,string type,int price, int quantity,string id)
{
        //Order = order;
        data_value->Com = com;
        data_value->Type = type;
        data_value->Price = price;
        data_value->Quantity = quantity;
        data_value->ID = id;
}
void Operations::Trade(struct Data_Store Order_first, int quantity1, struct Data_Store Order_second,int quantity2)
{
    cout<<"TRADE "<<Order_first.ID<<" "<<Order_first.Price<<" "<<quantity1<<" "<<
    Order_second.ID<<" "<<Order_second.Price<<" "<<quantity2<<endl;
}
void Operations::Oper_Buy_Sell(vector <string> operating_string)
{
    class Data_Store MinParameter;
    string COM =  operating_string[0];
    int numi = 0;
    //int Trade_quantity = 0;
    char * end;
    int price = static_cast<int>(strtol(operating_string[2].c_str(),&end,10));
    int quantity = static_cast<int>(strtol(operating_string[3].c_str(),&end,10));

    value_data(&MinParameter,COM,operating_string[1],price,quantity,operating_string[4]);


    if(Datanum == 0) // if LIst is empty, push in one
    {
        Datalist[Datanum++] = MinParameter;
    }
    else
    {
        if(!COM.compare("BUY"))  //
        {
            for(; numi < Datanum; numi++)
            {
                if(!Datalist[numi].Com.compare("SELL"))
                {
                    // the buy price should bigger than or equal wiht the sell, there is trade happeneds
                    if(Datalist[numi].Price <= MinParameter.Price)
                    {
                        //there is a trade happened
                        //then compare the quantity
                        if(Datalist[numi].Quantity > MinParameter.Quantity){ // sell more than buy
                            // change the sequence or not ???
                            Datalist[numi].Quantity -= MinParameter.Quantity;  //??? sequence

                            // output a trade
                            Trade(Datalist[numi],MinParameter.Quantity,MinParameter,MinParameter.Quantity);

                            break;

                        }
                        else{

                            Trade(Datalist[numi],Datalist[numi].Quantity,MinParameter,Datalist[numi].Quantity);

                            MinParameter.Quantity -= Datalist[numi].Quantity;

                            //delete the sell order
                            int j = numi;
                            for(;j < Datanum - 1;j++)
                            {
                                Datalist[j] = Datalist[j+1];
                            }
                            Datalist[j] = {0};
                            Datanum--;
                            numi--;

                            if(MinParameter.Quantity  == 0)
                                break;

                        }
                        //here should think the order or sequence
                    }
                }
            }

            if(MinParameter.Quantity > 0)
            {
                // put int the first
                for(numi = Datanum-1;numi > 0;numi--)
                    Datalist[numi+1] = Datalist[numi];
                Datalist[0] = MinParameter;
                Datanum++;
            }
        }
        else // sell order
        {

            for(; numi < Datanum; numi++)
            {
                if(!Datalist[numi].Com.compare("BUY")){

                    if(Datalist[numi].Price >= MinParameter.Price){

                        if(Datalist[numi].Quantity > MinParameter.Quantity){
                            //sell part current products
                            Datalist[numi].Quantity -= MinParameter.Quantity; //

                            // output a trade
                            Trade(MinParameter,MinParameter.Quantity,Datalist[numi],MinParameter.Quantity);


                        }
                        else{

                        }


                    }
                }
            }
        }
        // compare the price with the data in List

    }
    //cout<<operating_string[0]<<" "<<operating_string[1]<<" "<<operating_string[2]<<" "<<operating_string[3]<<" "<<operating_string[4]<<endl;
}
int main()
{

    string input_line, word;    // first input one line code ending by return
    int sec  = 0;

    while(getline(cin, input_line))
    {
        //cout<<input_line<<endl;
        vector <string> split_input;
		stringstream ss(input_line);
		while (ss >> word)
			split_input.push_back(word);  // input strings

        ClassOper Match_func("COMMAND","TYPE",0,0,"ID");
        Match_func.Match_com(split_input); // adjust the match

         while(Oper_List.size() > 0){
                cout<< " Oper_List.size()   = " <<Oper_List.size()<<endl ;
            ClassOper test = Oper_List.front();
            test.Print_elemets();
            Oper_List.pop_front();
         }

 #ifdef Test_List
        // list a class to test
        ClassOper MinParameter(sec++, split_input[0],split_input[1],1,2,split_input[4]);
        cout<<split_input[0]<<" "<<split_input[1]<<" "<<split_input[2]<<" "<<split_input[3]<<" "<<split_input[4]<<endl;

         Oper_List.push_back(MinParameter);
         if(sec > 1)
         {
             sec = 0;
             while(Oper_List.size() > 0){
                    cout<< " Oper_List.size()   = " <<Oper_List.size()<<endl ;
                ClassOper test = Oper_List.front();
                test.Print_elemets();
                Oper_List.pop_front();
             }
#endif
        /*
		while (!split_input.empty()) {
			word = split_input.front();
			split_input.pop();
             cout<<word;
            if(split_input.size()>= 1)
                cout<<" ";
		}
        */
		cout << endl;
		ss.clear();


    }


    while(1);
    return 0;
}
