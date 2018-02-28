#include <iostream>
#include <string>
#include <sstream>
#include  <vector>
#include <queue>
#include <list>
#include <stdlib.h>
using namespace std;

//#define Printf_Function //for test

typedef class Operations ClassOper;
typedef list <class Operations>  LIST_OPER;

LIST_OPER Oper_List;
//ClassOper Need_Modify();

class Operations{
    public:
       Operations(){
           Com="";
           Type="";
           Price =0;
           Quantity = 0;
           ID="";
       }
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
        //bool compare_nocase(ClassOper Hp1, ClassOper Hp2);
        void Oper_Print(vector <string> operating_string);
        void Oper_Modify(vector <string> operating_string);
        void Oper_Cancel(vector <string> operating_string);
        void Oper_Buy_Sell(vector <string> operating_string);
        void Trade(ClassOper Order_first, int quantity1, ClassOper Order_second,int quantity2);
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

    if(!COM.compare("BUY") || !COM.compare("SELL")){
        Oper_Buy_Sell(operating_string);
    }
    else if(!COM.compare( "CANCEL")){
        Oper_Cancel(operating_string);
    }
    else if(!COM.compare("MODIFY")){
        Oper_Modify(operating_string);
    }
    else if (!COM.compare("PRINT")){
        Oper_Print(operating_string);
    }
    else{
            cout<<"input wrong"<<endl;
    }
}
void Operations::Oper_Print(vector <string> operating_string){ //Print

    LIST_OPER SELL_List;
    LIST_OPER BUY_List;

    LIST_OPER::iterator itor;
    for(itor= Oper_List.begin(); itor !=  Oper_List.end();++itor){
        if(!itor->Com.compare("SELL")){
            if(SELL_List.empty()){
                SELL_List.push_back(*itor);
            }
            else{
                LIST_OPER::iterator Isell;
                int same_prince_sign = 0;
                for(Isell = SELL_List.begin(); Isell != SELL_List.end();++Isell)
                {
                    if(Isell->Price < itor->Price) // insert algorithm
                    {
                         break;
                    }
                    else if(Isell->Price == itor->Price)
                    {
                        same_prince_sign = 1;
                        Isell->Quantity += itor->Quantity;
                        break;
                    }
                }
                if(!same_prince_sign)
                 SELL_List.insert(Isell,*itor);

            }

        }
        else if(!itor->Com.compare("BUY"))
        {
           if(BUY_List.empty()){
                BUY_List.push_back(*itor);
            }
            else{
                LIST_OPER::iterator Ibuy;
                int same_prince_sign = 0;
                for(Ibuy = BUY_List.begin(); Ibuy != BUY_List.end();++Ibuy)
                {
                    if(Ibuy->Price < itor->Price){ // insert algorithm
                        break;
                    }
                    else if(Ibuy->Price == itor->Price){
                        same_prince_sign = 1;
                        Ibuy->Quantity += itor->Quantity;
                        break;
                    }
                }
                if(!same_prince_sign)
                    BUY_List.insert(Ibuy,*itor);
            }
        }
        else
        {
            cout<<"something wrong:"<<itor->Com<<endl;
        }
    }

    //print two values
    cout<<"SELL:"<<endl;
    LIST_OPER::iterator Isell;
    for(Isell = SELL_List.begin(); Isell != SELL_List.end();++Isell)
        cout<<Isell->Price<<" "<<Isell->Quantity<<endl;

    cout<<"BUY:"<<endl;
    LIST_OPER::iterator Ibuy;
    for(Ibuy = BUY_List.begin(); Ibuy != BUY_List.end();++Ibuy)
        cout<<Ibuy->Price<<" "<<Ibuy->Quantity<<endl;

}
void Operations::Oper_Modify(vector <string> operating_string){ //Modify some order

    string Order_id = operating_string[1];
    string Command = operating_string[2];
    char * end;
    int price = static_cast<int>(strtol(operating_string[3].c_str(),&end,10));
    int quantity = static_cast<int>(strtol(operating_string[4].c_str(),&end,10));

    LIST_OPER::iterator itor;
    ClassOper Need_Modify("","TYPE",0,0,"ID");
    int modify_sign = 0;
    for(itor= Oper_List.begin(); itor !=  Oper_List.end();++itor)
    {
        if(!itor->ID.compare(Order_id)){
            itor->Com = Command;
            itor->Price = price;
            itor->Quantity = quantity;

            modify_sign = 1;

            Need_Modify = *itor;

            Oper_List.erase(itor);
            break;
        }
    }
    if(modify_sign)
        Oper_List.push_back(Need_Modify);
}

void Operations::Oper_Cancel(vector <string> operating_string){ //cancel some order
    string Order_id = operating_string[1];
    LIST_OPER::iterator itor;
    for(itor= Oper_List.begin(); itor !=  Oper_List.end();++itor)
    {
        if(!itor->ID.compare(Order_id)){
           itor =  Oper_List.erase(itor); //here
            itor--;
        }
    }
}
void Operations::Trade(ClassOper Order_first, int quantity1, ClassOper Order_second,int quantity2)
{
    cout<<"TRADE "<<Order_first.ID<<" "<<Order_first.Price<<" "<<quantity1<<" "<<
    Order_second.ID<<" "<<Order_second.Price<<" "<<quantity2<<endl;
}

bool compare_nocase(ClassOper Hp1, ClassOper Hp2)
{
    return (Hp1.Price > Hp2.Price);
}
bool compare_sell_Low_price(ClassOper Hp1, ClassOper Hp2)
{
    return (Hp1.Price < Hp2.Price);
}
void Operations::Oper_Buy_Sell(vector <string> operating_string)
{
    char * end;
    int price = static_cast<int>(strtol(operating_string[2].c_str(),&end,10));
    int quantity = static_cast<int>(strtol(operating_string[3].c_str(),&end,10));
    ClassOper MinParameter(operating_string[0],operating_string[1],price,quantity,operating_string[4]);

    if(Oper_List.empty()) // if LIst is empty, push in one
    {
        //if it the first one, delete it
        if(!MinParameter.Type.compare("GFD"))
            Oper_List.push_back(MinParameter);
    }
    else
    {
        list <class Operations>::iterator itor;

        string COM =  operating_string[0];
        if(!COM.compare("BUY")) // buy
        {
            LIST_OPER Oper_Sell_Low_Price;
            for(itor= Oper_List.begin(); itor !=  Oper_List.end(); ++itor){ //insert sort
                        if(!itor->Com.compare("SELL"))
                                Oper_Sell_Low_Price.push_back(*itor);

            }
            Oper_Sell_Low_Price.sort(compare_sell_Low_price); //compare_nocase
            for(itor= Oper_Sell_Low_Price.begin(); itor !=  Oper_Sell_Low_Price.end(); ++itor){ //sell
              //if(itor->Price < MinParameter.Price)
               //     break;
                if(MinParameter.Quantity <= 0)
                    break;

                LIST_OPER::iterator itor_inside;
                for(itor_inside= Oper_List.begin(); itor_inside !=  Oper_List.end();++itor_inside)
                {
                    if(!itor_inside->ID.compare(itor->ID)) // sell
                    {
                        //start to sell
                        if(itor_inside->Price <= MinParameter.Price)
                        {
                                if(itor_inside->Quantity > MinParameter.Quantity)
                                {
                                    itor_inside->Quantity  -= MinParameter.Quantity;  // sequence ???

                                    ClassOper Change = *itor_inside;

                                    itor_inside = Oper_List.erase(itor_inside);

                                    Oper_List.push_back(Change);


                                    Trade(*itor_inside, MinParameter.Quantity,MinParameter,MinParameter.Quantity);
                                    MinParameter.Quantity = 0;

                                }
                                else
                                {
                                    MinParameter.Quantity -= itor_inside->Quantity;

                                    Trade(*itor_inside, itor_inside->Quantity,MinParameter,itor_inside->Quantity);

                                   itor_inside = Oper_List.erase(itor_inside);

                                }
                        }
                        break;
                    }
                }
            }
            if(MinParameter.Quantity > 0){
                if(!MinParameter.Type.compare("GFD"))
                    Oper_List.push_back(MinParameter);
            }
        }
        else // SELL
        {
            //LIST_OPER::iterator itor;
            LIST_OPER Oper_Buy_High_Price;
             //Oper_List.push_back(MinParameter);

           for(itor= Oper_List.begin(); itor !=  Oper_List.end(); ++itor){ //insert sort
                if(!itor->Com.compare("BUY"))
                        Oper_Buy_High_Price.push_back(*itor);

           }/*
           Oper_Buy_High_Price.sort((ClassOper H1, ClassOper H2) => {
                                        return H2.Price.compareto(H1.Price);
            });
            */
            Oper_Buy_High_Price.sort(compare_nocase); //compare_nocase
           for(itor= Oper_Buy_High_Price.begin(); itor !=  Oper_Buy_High_Price.end(); ++itor){ //insert sort
                if(itor->Price < MinParameter.Price)
                    break;
                if(MinParameter.Quantity <= 0)
                    break;

                LIST_OPER::iterator itor_inside;

                for(itor_inside = Oper_List.begin(); itor_inside !=  Oper_List.end();++itor_inside){
                    if(!itor->ID.compare(itor_inside->ID)) // sell
                    {
                        //start to sell
                        if(itor_inside->Price >= MinParameter.Price)
                        {
                                if(itor_inside->Quantity > MinParameter.Quantity)
                                {
                                    itor_inside->Quantity  -= MinParameter.Quantity;  // sequence ???

                                    ClassOper Change = *itor_inside;

                                    itor_inside = Oper_List.erase(itor_inside);

                                    Oper_List.push_back(Change);


                                    Trade(*itor_inside, MinParameter.Quantity,MinParameter,MinParameter.Quantity);
                                    MinParameter.Quantity = 0;

                                }
                                else
                                {
                                    MinParameter.Quantity -= itor_inside->Quantity;

                                    Trade(*itor_inside, itor_inside->Quantity,MinParameter,itor_inside->Quantity);

                                   itor_inside = Oper_List.erase(itor_inside);
                                }
                        }
                        break;
                    }
                }
           }
            if(MinParameter.Quantity > 0)
            {
                 //MinParameter.Print_elemets();
                 if(!MinParameter.Type.compare("GFD"))
                    Oper_List.push_back(MinParameter);
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

#ifdef Printf_Function
        //print
        LIST_OPER::iterator itor;
        for(itor= Oper_List.begin(); itor !=  Oper_List.end();++itor)
        {
           itor->Print_elemets();
        }
        cout<<endl;
#endif
        /*
         while(Oper_List.size() > 0){
                cout<< " Oper_List.size()   = " <<Oper_List.size()<<endl ;
            ClassOper test = Oper_List.front();
            test.Print_elemets();
            Oper_List.pop_front();
         }
        */
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

		ss.clear();


    }
    return 0;
}
