#include<iostream>
#include<ctime>
#include<string>
using namespace std;

class Customer;
class Product;
class Stock;
class ORDER;
void displayProduct();
int np=0;
Product* p[5];
Customer* c[100];
int nc=0;
ORDER* o[100];
int no=0;

class Stock
{
private:
    Product *ps;
    int productId;
    int shopNo;
    friend void stockDisplay(int aa);

public:
    int quantity;
    //Stock();
    Stock(int id=0,int q=0,int sn=0);
    void inputStock();
    void addStock();
    void modifyStock();
    bool selectStockItem(int id);


};

class Product
{
  private:
     string ProductType;
     friend void displayProduct();
     friend void stockDisplay(int aa);
  public:
      float ProductPrice;
      int ProductId;
      Stock *s;
      int ns = 0;
    Product(int pid=0,float prp=0,char *c="0"):ProductId(pid),ProductPrice(prp),ProductType(c){}
    Product (const Product &p)
    {
        ProductId=p.ProductId;
        ProductPrice=p.ProductPrice;
        ProductType=p.ProductType;
    }
    void AddProduct();
    void ModifyProduct();
    int SelectProduct();
    void display()
    {
        cout << "\nTHE AVAILABLE PRODUCTS ARE\n\n";
        for(int i=0;i<np;i++)
        {
            cout << i+1 << " -> " << ProductType << "\n";
        }
    }
    bool ssStock(int n);
    /*void stockDisplay()
    {
        cout << "\n";
        for(int i=0;i<5;i++)
        {
           // cout << s[i]->shopNo << "\n";
        }
        cout << "\n";
    }*/


};

class Customer
{
private:
    string customerName;
    int unique_id;
    string address;
    long long phone;

public:
    int customerID;
    Customer();
    Customer(const Customer &c);
    void addCustomer();
    void deleteCustomer();
    void editCustomer();
    bool operator ==(int data);

};

class ORDER
{
private:
    Customer c;
    int Orderid,Customerid;
    float Amount;
    string CustomerName;
    time_t now;
    char *dt;
    Product *product[5];
public:
    int oid;
    int n;
    int Productid;

    ORDER()
    {
        cout << "\nTHE UNIQUE ID OF ORDER -> " << (no+1) << "\n\n";
        cout << "ENTER ORDER ID: ";
        cin >> Orderid;
        cout << "ENTER CUSTOMER ID: ";
        cin >> Customerid;
        cout << "ENTER CUSTOMER NAME: ";
        cin >> CustomerName;
        now=time(0);
        dt=ctime(&now);
        Productid=0;
        Amount = 0;
    }

    void CreateOrder();
    void EditOrder();
};

//------------------------------------------------------   PRODUCT   -------------------------------------------------------------------------
void Product::AddProduct()
{

    cout << "\n\n";
    cout<<"Enter the Product id: \t";
    cin >> ProductId;
    int abc;
    abc = ProductId;
    cout<<endl;
    cout<<"Enter the Product price: \t";
    cin>> ProductPrice;
    cout<<endl;
    cout<<"Enter the Product type:\t";
    cin>>ProductType;
    s = new Stock(abc);
    np++;












}

void Product::ModifyProduct()
{
     int n;
        cout<<"what do you want to modify ?\n1.ProductId \n2.Price \n3.Type";
        cin >> n;
        cout << "\n\n";
        if(n==1)
        {
        cout<<"Enter the new Productid: \t";
        cin>>ProductId;
        }
        else if(n==2)
        {
        cout<<"Enter the new Product price: \t";
        cin>>ProductPrice;
        }
        else if(n==3)
        {
        cout<<"Enter the Product name: \t";
        cin>>ProductType;
        }
        else
        {
            cout << "\nINVALID INPUT \n\n";
        }
        cout << "\n";
}

int Product::SelectProduct()
{

    return ProductId;

   /* int n,i=0,a;
    cout << "ENTER THE QUANTITY: ";
    cin >> n;
    bool m;
    do
    {
        m = s->selectStockItem(n);
        if(m == true)
        {
            a=1;
            break;
        }
        i++;
    }while(m != true);
    if (a == 1)
        cout << "\nSUCCESSFULL\n\n";
    else
        cout << "\nUNSUCCESSFULL\n\n";
*/


}

bool Product :: ssStock(int n)
{
    bool qwe;
    for(int i=0;i<5;i++)
    {
        qwe = s->selectStockItem(n);
        if (qwe == true)
            return true;
    }
    return false;
}

//--------------------------------------------------------   ORDER   -------------------------------------------------------------
void ORDER::CreateOrder()
{
    int indexValue,n;
    if(np==0)
    {
        cout << "\nNO PRODUCTS AVAILABLE\n\n";
    }
    else
    {
        cout << "\nPRODUCTS AVAILABLE\n";
        displayProduct();
        cout<<"\n\tENTER THE OPTION : ";
        cin >> indexValue;
        if(indexValue <= (np+1))
    {
        int value =  p[indexValue-1]->SelectProduct();
        Productid = value;
        cout << "ENTER THE QUANTITY: ";
        cin >> n;
        bool xyz;
        xyz= false;
        for(int i=0;i<5;i++)
        {
            xyz = p[indexValue-1]->s->selectStockItem(n);
            if(xyz == true)
                Amount = p[indexValue-1]->ProductPrice * n;
                break;
        }
        if (xyz == true)
        {
            cout << "\nORDER PLACED SUCCESSFULLY\n\n";
        }
        else
        {

        }




    }
    else
    {
        cout << "\nINVALID INPUT !\n\n";

    }


    }


}
void ORDER::EditOrder()
{
       int indexValue,n;
       cout << "\nPRODUCTS AVAILABLE\n\n";
       displayProduct();
       cout << "\nENTER THE OPTION: ";
       cin >> indexValue;



               if(indexValue <= (np+1))
    {
        int value =  p[indexValue-1]->SelectProduct();
        Productid = value;
        cout << "ENTER THE QUANTITY: ";
        cin >> n;
        bool xyz;
        xyz= false;
        for(int i=0;i<5;i++)
        {
            xyz = p[indexValue-1]->s->selectStockItem(n);
            if(xyz == true)
                Amount = p[indexValue-1]->ProductPrice * n;
                break;
        }
        if (xyz == true)
        {
            cout << "\nORDER PLACED SUCCESSFULLY\n\n";
        }
        else
        {

        }

    }
    else
    {
        cout << "\nINVALID INPUT\n\n";
    }



}

//------------------------------------------------------   CUSTOMER    -------------------------------------------------------------
Customer :: Customer()
{
    customerID = 0;
}

Customer :: Customer(const Customer &c)
{
    customerID = c.customerID;
    customerName = c.customerName;
    address = c.address;
    phone = c.phone;
}

void Customer :: addCustomer()
{
    unique_id = nc+1;
    cout << "\nYOUR UNIQUE ID -> " << unique_id << "\n\n";
    cout << "ENTER THE CUSTOMER ID: ";
    cin >> customerID;
    cout << "ENTER THE CUSTOMER NAME: ";
    cin >> customerName;
    cout << "ENTER THE ADDRESS: ";
    cin >> address;
    cout << "ENTER THE CUSTOMER PHONE NO: ";
    cin >> phone;
}
void Customer :: deleteCustomer()
{
    //delete &customerID;
    //delete &customerName;
    //delete &address;
    //delete &phone;
    cout << "\nDELETE CALLED\n";
    delete this;
}

void Customer :: editCustomer()
{
    int opt=1;
    int a;
    while(opt == 1)
    {
        cout << "\n1 -> NAME\n";
        cout << "2 -> ADDRESS\n";
        cout << "3 -> PHONE NUMBER\n";
        cin >> a;
        system("CLS");
        if(a==1)
        {
            cout << "\nENTER THE NAME: ";
            cin >> customerName;
        }
        else if(a == 2)
        {
            cout << "\nENTER THE ADDRESS: ";
            cin >> address;
        }
        else if(a==3)
        {
            cout << "\nENTER THE PHONE NUMBER: ";
            cin >> phone;
        }
        else
        {
            cout << "\nINVALID INPUT\n";
        }
        system("CLS");
        cout << "\nDO YOU WANT TO EDIT AGAIN ?\n1 -> YES\n2 -> NO\n";
        cin >> opt;
        system("CLS");
    }
}

bool Customer :: operator ==(int data)
{
    if(customerID == data)
        return true;
    else
        return false;
}

//----------------------------------------------------------   STOCK   ----------------------------------------------------
/*Stock :: Stock()
{
    productId = 00;
    quantity = 0;
    shopNo = 0;
}*/



void Stock :: inputStock()
{
    cout << "\nENTER THE SHOP NO: ";
    cin >> shopNo;
    cout << "ENTER THE QUANTITY: ";
    cin >> quantity;
}

Stock :: Stock(int id,int q,int sn)
{
    productId = id;
    quantity =q;
    shopNo = sn;
    this->inputStock();

    cout << "\n\nTHIS IS A CHECK\n\n\n";
    cout << productId << "\n" << quantity << "\n" << shopNo << "\n\n";

}

void Stock :: addStock()
{
    int x;
    cout << "\nWHAT IS THE NUMBER OF QUANTITIES THAT YOU WANT TO ADD TO THE STOCK ? \n\n";
    cin >> x;
    cout << "\n" << x << "\t" << quantity << "\n\n";
    this->quantity += x;//------------------------------------------------------------------------------------HERE THERE IS A PROBLEM--------------------
    cout << "STOCK ADDED SUCCESSFULLY\n\n";
}

void Stock :: modifyStock()
{
    int option;
    cout << "\nWHAT DO YOU WANT TO MODIFY?\n";
    cout << "1 -> SHOP NO\n";
    cout << "2 -> QUANTITY\n";
    cin >> option;
    system("CLS");
    if(option == 1)
    {
        cout << "\nENTER THE SHOP NO: \n";
        cin >> shopNo;
        system("CLS");
        cout << "\nSHOP NUMBER CHANGED SUCCESSFULLY\n\n";
    }
    else if(option == 2)
    {
        int option1;
        cout << "\n1 -> ADD\n2 -> REMOVE\n";
        cin >> option1;
        system("CLS");
        if(option1 == 1)
        {
            int n;
            cout << "ENTER THE NUMBER OF QUANTITY: ";
            cin >> n;
            system("CLS");
            quantity = quantity + n;
            cout << "\nSTOCK ADDED SUCCESSFULLY\n\n";
        }
        else if(option == 2)
        {
            int n;
            cout << "ENTER THE QUANTITY TO REMOVE: ";
            cin >> n;
            system("CLS");
            if(quantity >= n)
            {
                quantity = quantity - n;
                cout << "\nSTOCK ADDED SUCCESSFULLY\n\n";
            }
            else
            {
                cout << "\nSHORTAGE OF STOCK\n\n";
            }

        }
    }

}

bool Stock :: selectStockItem(int n)
{
    if(n <= quantity)
    {
        quantity = quantity -n;
        return true;
    }
    else
    {
        return false;
    }
}

void displayProduct()
{
    if(np == 0)
    {
        cout << "\nNO PRODUCTS AVAILABLE\n\n";
    }
    else
    {
        for(int i=0;i<np;i++)
    {
        cout << i+1 << " -> " <<  p[i]->ProductType << "\n";
    }
    }

}

void stockDisplay(int aa)
{
    cout << "\n";
        for(int i=0;i<5;i++)
        {
            cout << (p[aa-1]->s)->shopNo << "\n";
        }
        system("pause");
        cout << "\n";

}

int searchCustomerIndex(int *d)
{
    int r;
    cout << "SEARCH\n";
    for(int i=0;i<100;i++)
    {
        cout << "SEARCH\n";
        if((c[i]->customerID) == *d)
            {
                r=i;
                return r;
            }
    }
    return -1;
}

//--------------------------------------    MAIN FUNCTION   ------------------------------------------------------------------------
int main()
{


    while(1)
    {
        int opt;
        system("CLS");
        cout << "\n1 -> CUSTOMER\n";
        cout << "2 -> ORDER\n";
        cout << "3 -> PRODUCT\n";
        cout << "4 -> EXIT\n";
        cin >> opt;
        system("CLS");
        switch(opt)
        {
        case 1:
            int option1;
            cout << "\n1 -> ADD CUSTOMER\n";
            cout << "2 -> EDIT CUSTOMER\n";
            cout << "3 -> DELETE CUSTOMER\n";
            cin >> option1;
            system("CLS");
            if(option1 == 1)
            {
                if (nc < 100)
                {
                    c[nc] = new Customer();
                    c[nc]->addCustomer();
                    nc++;
                    system("CLS");
                    cout << "\nCUSTOMER DATA ADDED SUCCESSFULLY\n\n";
                }
                else
                {
                    cout << "\nDATABASE FULL !\n\n";
                }

            }
            else if(option1 == 2)
            {
                int index;
                cout << "\nENTER YOUR UNIQUE ID: ";
                cin >> index;
                system("CLS");
                if(index <= nc)
                {
                    c[index-1]->editCustomer();
                }
                else
                {
                    cout << "\nINVALID UNIQUE ID\n\n";
                }

            }
            else if(option1 == 3)
            {
                int index;
                cout << "\nENTER YOUR UNIQUE ID: ";
                cin >> index;
                system("CLS");
                if(index <= nc)
                {
                    c[index-1]->deleteCustomer();

                }
                else
                {
                    cout << "\nINVALID UNIQUE ID\n\n";
                }
            }
            else
            {
                cout << "\nINVALID INPUT\n\n";
            }

            break;
        case 2:
            int option2;
            cout << "\n1 -> CREATE ORDER\n";
            cout << "2 -> EDIT ORDER\n";
            cin >> option2;
            system("CLS");
            if(option2 == 1)
            {
                o[no] = new ORDER();
                o[no]->CreateOrder();


                no++;
            }
            else if(option2 == 2)
            {
                int index;
                cout << "\nENTER ORDER UNIQUE ID: ";
                cin >> index;
                system("CLS");
                if(index <= no)
                {
                    o[index-1]->EditOrder();

                }
                else
                {
                    cout << "\nINVALID ORDER UNIQUE ID\n\n";
                }
            }
            else
            {
                cout << "\nINVALID INPUT\n\n";
            }


            break;
        case 3:
            system("CLS");
            int pass;
            cout << "\t\t\t\tNOTE: PASSWORD -> 1234\n";
            cout << "ENTER THE PASSWORD: ";
            cin >> pass;
            system("CLS");
            if(pass == 1234)
            {

                int option3;
                cout << "\n1 -> ADD PRODUCT\n";
                cout << "2 -> MODIFY PRODUCT\n";
                cout << "3 -> ADD STOCK\n";
                cout << "4 -> MODIFY STOCK\n";
                cin >> option3;
                system("CLS");
                if(option3 == 1)
                {
                    p[np] = new Product;
                    p[np]->AddProduct();
                }
                else if(option3 == 2)
                {
                    displayProduct();
                    if(np != 0)
                    {
                        int indexValue;
                        cout << "ENTER THE PRODUCT OPTION: ";
                        cin >> indexValue;
                        p[indexValue-1]->ModifyProduct();

                    }

                }
                else if(option3 == 3)
                {
                    displayProduct();
                    if(np !=0)
                    {
                        cout << "\n" << "\nENTER THE PRODUCT OPTION -> ";
                        int indexValue3;
                        cin >> indexValue3;
                        cout << "BEFORE ADD STOCK\n\n";
                       // system("CLS");
                        p[indexValue3 -1]->s->addStock();
                    }


                }
                else if(option3 == 4)
                {
                    displayProduct();
                    if(np !=0)
                    {
                        cout << "\n" << "\nENTER THE PRODUCT OPTION -> ";
                        int indexValue4;
                    cin >> indexValue4;
                    system("CLS");
                    if(indexValue4 <= np)
                    {
                        p[indexValue4 -1]->s->modifyStock();
                    }
                    else
                    {
                        cout << "\nINVALID INPUT\n\n";
                    }
                    }
                }
                else
                {
                    cout << "\nINVALID INPUT\n\n";
                }

            }
            else
            {
                cout << "\nINVALID PASSWORD\n\n";
            }

            break;
        case 4:
            exit(0);

            break;
        default:
            cout << "\nINVALID INPUT\n\n";
        }
        system("pause");
    }



    return 0;
}
