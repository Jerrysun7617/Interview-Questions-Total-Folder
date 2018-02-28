#include <iostream>
#include <string>
#include <sstream>
#include  <vector>
#include <queue>
#include <list>
#include <stdlib.h>
using namespace std;

typedef class Operations ClassOper;
typedef list <class Operations>  LIST_OPER;
LIST_OPER Oper_List;
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
bool compare_Increase(ClassOper Hp1, ClassOper Hp2)
{
    return (Hp1.Price < Hp2.Price);
}
bool compare_Decrease(ClassOper Hp1, ClassOper Hp2)
{
    return (Hp1.Price > Hp2.Price);
}

void Operations::Print_elemets(void)
{
    cout<<Com<<" "<<Type<<" "<<Price<<" "<<Quantity<<" "<<ID<<endl;
}
void Operations::Match_com(vector <string> operating_string){
    //if(operating_string.size() == 0)
    //    cout<<"input wrong"<<endl;
    if(operating_string.empty())
        return;

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
    if(operating_string.size() != 1)
        return;
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

   if(operating_string.size() != 5)
        return;

    string Order_id = operating_string[1];
    string Command = operating_string[2];
    char * end;
    int price = static_cast<int>(strtol(operating_string[3].c_str(),&end,10));
    int quantity = static_cast<int>(strtol(operating_string[4].c_str(),&end,10));

     if(price <= 0 || quantity <=0 || Order_id.empty() ||Command.empty())
        return;
     if(Command.compare("BUY")&&Command.compare("SELL"))
        return;

    LIST_OPER::iterator itor;
    ClassOper Need_Modify("","",0,0,"");

    int modify_sign = 0;
    for(itor= Oper_List.begin(); itor !=  Oper_List.end();)
    {
        if(!itor->ID.compare(Order_id) && itor->Type.compare("IOC")){
            modify_sign = 1;
            itor->Com = Command;
            itor->Price = price;
            itor->Quantity = quantity;
            Need_Modify = *itor;
            itor =  Oper_List.erase(itor);
        }
        else
            ++itor;
    }

    if(modify_sign){
       // if(modify_Command){
            vector <string> operating_string;

            stringstream ss;
            string str;

            operating_string.push_back(Need_Modify.Com);
            operating_string.push_back(Need_Modify.Type);

            ss<<Need_Modify.Price;
            ss>>str;
            operating_string.push_back(str);

            stringstream ss2;
            string str2;
            ss2<<Need_Modify.Quantity;
            ss2>>str2;
            //cout<<"Quantity:"<<str2<<endl;
            operating_string.push_back(str2);

            ss.clear();
            ss2.clear();

            operating_string.push_back(Need_Modify.ID);
            //Need_Modify.Print_elemets();
            Oper_Buy_Sell(operating_string);
    }
}

void Operations::Oper_Cancel(vector <string> operating_string){ //cancel some order

    if(operating_string.size() != 2)
        return;
     string Order_id = operating_string[1];
    if(Order_id.empty())
        return;

    LIST_OPER::iterator itor;
    for(itor= Oper_List.begin(); itor !=  Oper_List.end();)
    {
        if(!itor->ID.compare(Order_id)){
           itor =  Oper_List.erase(itor); //here

        }
        else
            ++itor;
    }
}
void Operations::Trade(ClassOper Order_first, int quantity1, ClassOper Order_second,int quantity2){
    cout<<"TRADE "<<Order_first.ID<<" "<<Order_first.Price<<" "<<quantity1<<" "<<
    Order_second.ID<<" "<<Order_second.Price<<" "<<quantity2<<endl;
}

void Operations::Oper_Buy_Sell(vector <string> operating_string)
{
    if(operating_string.size() != 5)
        return;
    char * end;
    int price = static_cast<int>(strtol(operating_string[2].c_str(),&end,10));
    int quantity = static_cast<int>(strtol(operating_string[3].c_str(),&end,10));

    //cout<<operating_string.size()<<endl;

    if(price <= 0 || quantity <=0 || operating_string[4].empty())
        return;

    if(operating_string[0].compare("BUY")&&operating_string[0].compare("SELL"))
        return;

    if(operating_string[1].compare("IOC")&&operating_string[1].compare("GFD"))
        return;
    ClassOper MinParameter(operating_string[0],operating_string[1],price,quantity,operating_string[4]);

    if(Oper_List.empty()) // if LIst is empty, push in one
    {
        //if it the first one, delete it
        if(!MinParameter.Type.compare("GFD"))
            Oper_List.push_back(MinParameter);
    }
    else{
        //test id
        list <class Operations>::iterator test_id;
        for(test_id= Oper_List.begin(); test_id !=  Oper_List.end(); ++test_id){ //insert sort
                    if(!test_id->ID.compare(MinParameter.ID))
                       return;
        }
        list <class Operations>::iterator itor;
        string COM =  operating_string[0];
        if(!COM.compare("BUY")) // buy
        {
            LIST_OPER Oper_Sell_Low_Price;
            for(itor= Oper_List.begin(); itor !=  Oper_List.end(); ++itor){ //insert sort
                        if(!itor->Com.compare("SELL"))
                                Oper_Sell_Low_Price.push_back(*itor);
            }
            Oper_Sell_Low_Price.sort(compare_Increase); //compare_nocase

            for(itor= Oper_Sell_Low_Price.begin(); itor !=  Oper_Sell_Low_Price.end(); ++itor){ //sell
              if(itor->Price > MinParameter.Price) //
                    break;
                if(MinParameter.Quantity <= 0)
                    break;

                LIST_OPER::iterator itor_inside;
                for(itor_inside= Oper_List.begin(); itor_inside !=  Oper_List.end();)
                {
                    if(!itor_inside->ID.compare(itor->ID)) // sell
                    {
                        //start to sell
                        if(itor_inside->Price <= MinParameter.Price)
                        {
                                if(itor_inside->Quantity > MinParameter.Quantity)
                                {
                                    itor_inside->Quantity  -= MinParameter.Quantity;  // sequence ???
                                    Trade(*itor_inside, MinParameter.Quantity,MinParameter,MinParameter.Quantity);
                                    MinParameter.Quantity = 0;

                                    ClassOper Change(itor_inside->Com,itor_inside->Type,itor_inside->Price,itor_inside->Quantity,itor_inside->ID);

                                    itor_inside = Oper_List.erase(itor_inside);

                                    Oper_List.push_back(Change);
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
                    else
                        ++itor_inside;
                }
            }
            if(MinParameter.Quantity > 0){
                if(!MinParameter.Type.compare("GFD"))
                    Oper_List.push_back(MinParameter);
            }
        }
        else // SELL
        {
            LIST_OPER Oper_Buy_High_Price;
            for(itor= Oper_List.begin(); itor !=  Oper_List.end(); ++itor){ //insert sort
                if(!itor->Com.compare("BUY"))
                        Oper_Buy_High_Price.push_back(*itor);
           }
            Oper_Buy_High_Price.sort(compare_Decrease); //compare_nocase

           for(itor= Oper_Buy_High_Price.begin(); itor !=  Oper_Buy_High_Price.end(); ++itor){ //insert sort
                if(itor->Price < MinParameter.Price)
                    break;
                if(MinParameter.Quantity <= 0)
                    break;

                LIST_OPER::iterator itor_inside;

                for(itor_inside = Oper_List.begin(); itor_inside !=  Oper_List.end();){
                    if(!itor->ID.compare(itor_inside->ID)) // sell
                    {
                        //start to sell
                        if(itor_inside->Price >= MinParameter.Price)
                        {
                                if(itor_inside->Quantity > MinParameter.Quantity)
                                {
                                    itor_inside->Quantity  -= MinParameter.Quantity;  // sequence ???

                                    Trade(*itor_inside, MinParameter.Quantity,MinParameter,MinParameter.Quantity);

                                    ClassOper Change(itor_inside->Com,itor_inside->Type,itor_inside->Price,itor_inside->Quantity,itor_inside->ID);


                                    itor_inside = Oper_List.erase(itor_inside);

                                    Oper_List.push_back(Change);


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
                    else
                        ++itor_inside;
                }
           }
            if(MinParameter.Quantity > 0){
                 //MinParameter.Print_elemets();
                 if(!MinParameter.Type.compare("GFD"))
                    Oper_List.push_back(MinParameter);
            }
      }
   }
}
int main()
{
    string input_line;
    while(getline(cin, input_line))
    {
        //cout<<input_line<<endl;
        string word;    // first input one line code ending by return
        vector <string> split_input;
		stringstream ss(input_line);
		while (ss >> word)
			split_input.push_back(word);  // input strings

        ClassOper Match_func("","",0,0,"");
        Match_func.Match_com(split_input); // adjust the match

		ss.clear();
    }
    return 0;
}
