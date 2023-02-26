/********************************************************************
* 	Author: Muhammad Owais Mushtaq      							*
*   Roll No: 18k-1177    				  							*
* 	Project Name: PraSen Counter        							*
* 	Starting Date: October 18, 2019                  				*   
*   Finished Date: December 29, 2019 	                            *
*********************************************************************/

#include<iostream>
#include<string.h>
#include<fstream>
#include<sstream>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>

using namespace std;

// this is global variable
COORD coord= {0,0}; 
int FileCount=0;

//Prototype for Function BoxFill
void BoxFill();

//Prototype for Function curser
void curser(int n);

// Node Class for the Linked List name as 'SentenceList', it carrys string for single sentence
class SLnode{
	
	public:
		string sentence;
		SLnode *next;
		
		SLnode(){
			
			next=NULL;
			
		}
		SLnode(string s){
			
			sentence=s;
			next=NULL;
			
		}
		SLnode(string s, SLnode *m){
		
			sentence=s;
			next=m;
		
		}

};

/*SentenceList is Singly Linked list based class, 
used for storing Sentences of single file to fulfill our Searching objective*/
class SentenceList{

	
	public:

		SLnode *head; 
		SLnode *tail;
		int SentenceCount;
	
		
		SentenceList(){
		
			head=NULL;
			tail=NULL;
			SentenceCount=0;
			
		}
		
		void InsertAtHead(SLnode *n){
		
			if(head==0){
				head=n;
				tail=n;
				
			}else{
				n->next=head;
				head=n;
				}
			SentenceCount++;
		}
		
		void InsertAtTail(SLnode *n){
			
			if(head==0){
				head=n;
				tail=n;
				
			}
			tail->next=n;
			tail=n;
			SentenceCount++;
		}
		
		void InsertAtIndex(int n, SLnode *m){
			
			if(n==0){
				
				InsertAtHead(m);
				
			}else if(n==SentenceCount-1){
				
				InsertAtTail(m);
				
			}else if(n>0 && n<SentenceCount-1){
				
				SLnode *pre;
				SLnode *curr;
				curr=head;
				
				for(int i=0; i<n; i++){
					pre=curr;
					curr=curr->next;	
				}
				
				pre->next=m;
				m->next=curr;
				pre=NULL;
				curr=NULL;
				SentenceCount++;
				
		}else{
		
			cout<<"Invalid Index! "<<endl;
			
		}
	}
		
		void DeleteAtHead(){
		
		SLnode *temp;
		temp= head->next;
		
		if(head!=0){
			head=NULL;
		}
		head=temp;
		SentenceCount--;
	}
	
		void DeleteAtTail(){
		
			SLnode *pre;
			SLnode *curr;
			curr=head;
	
			for(int i=0; i<SentenceCount; i++){
				pre=curr;
				curr=curr->next;	
			}
			
			pre->next=NULL;
			tail=pre;
			SentenceCount--;
	}
	
		void DeleteAtIndex(int n){
		
		if(n==0){
				
				DeleteAtHead();
				
			}else if(n==SentenceCount-1){
				
				DeleteAtTail();
				
			}else if(n>0 && n<SentenceCount-1){
				
				SLnode *pre;
				SLnode *curr;
				curr=head;
				
				for(int i=0; i<n; i++){
					pre=curr;
					curr=curr->next;	
				}
				
				pre->next=curr->next;
				curr=NULL;
				SentenceCount--;
				
		}else{
			cout<<"Invalid Index! ";
				
		}	
	}
	
		void print(){
			
				SLnode *curr;
				curr=head;
				cout<<"\nTotal Number of Sentences = "<<SentenceCount<<endl<<endl;
				cout<<"  INDEX   |                Sentence                                   "<<endl;
				cout<<"--------------------------------------------------------------------"<<endl;
				for(int i=0; i<SentenceCount; i++){
				
					cout<<"\t"<<i+1<<" | "<<curr->sentence<<endl;
					curr=curr->next;
					
					
				}
		}
	
		//this fuction puts or copy the data of user into linkedlist's 
		void FillList(string s){
			
			SLnode *n1= new SLnode(s);
			InsertAtTail(n1);
			
		}
		
		string& operator[](int index){
			
            if(index > SentenceCount-1){
            	cout<<"\n\n\t\t\t\t\t Sorry! The Number of Sentences in this File are lower than your input.";
            }else{
             
			    SLnode *current;
                current = head;
                while(current!=0 && index-- > 0){
                    current = current->next;
                }

                return current->sentence;
            }

        }				

};

// This Template node class is for templetise Singly Linked list class Named as SSL
template<class t>
class node{

    private:

        t data;
        node *next;

    public:
    	
        node():data(0),next(0){};

        node(t data, node<t> *obj = 0){
           
		    this->data = data;
            this->next = obj;
        
		}

        node<t>* get_next(){
        
		    return next;
        
		}

        void set_next(node *next){
           
		    this->next = next;
       
	    }
        

        t& get_data(){
        	
            return data;
        }

       void set_data(t data){
       	
            this->data = data;
        
		}
		
};

/* This Template Singly Linked List class is used for generating templetise Queue class*/
template<class t>
class sll{

    private:
        int size;
        node<t> *head;
        node<t> *tail;
        void delete_list(){
            
			if(head!=0){
                node<t> *current;
                node<t> *temp;
                current = head;
                
                while(current!= 0){
                        temp = current;
                        current = current->get_next();
                        delete temp;
                    }
                }
            size = 0;
        }

    public:
    	
        sll():size(0),head(0){}

        sll(t data){
        	
            node<t> *newnode;
            newnode = new node<t>(data);
            head = newnode;
            tail = newnode;
            size = 1;
            
        }

        sll(sll<t> const&rhs){
        	
            this->head = 0;
            node<t> *ptr = rhs.head;
          
		    while(ptr!=0){
                insert_at_tail(ptr->get_data());
                ptr = ptr->get_next();
            }
        }

        sll<t>& operator =(const sll<t>&rhs){
            
			if(this != &rhs){
               
			    delete_list();
                this->head = 0;
                node<t> *ptr = rhs.head;
              
			    while(ptr!=0){
                    insert_at_tail(ptr->get_data());
                    ptr = ptr->get_next();
                }
            }
            return (*this);
        }

        int get_size(){
        	
            return size;
        
		}

        void insert_at_head(t data){
        	
            node<t> *newnode;
            newnode  = new node<t>(data);
            if(head == 0){
                head = newnode;
                tail = newnode;
                size = 1;
            }
            else{
                newnode->set_next(head);
                head = newnode;
                size++;
            }
        }
        

        void insert_at_tail(t data){
        	
            node<t> *newnode;
            newnode = new node<t>(data);

            if(head == 0){
                head = newnode;
                tail = newnode;
                size = 1;
            }
            else{
                tail->set_next(newnode);
                tail = newnode;
                size++;
            }
        }

        void insert_at_index(t data,int index){
            
			node<t> *newnode;
            node<t> *current;
            newnode = new node<t>(data);
            if(index > size){
                cout << "This index exceeds the size of list";
            }
            else if(index == size){
                tail->set_next(newnode);
                tail = newnode;
                size++;
            }

            else{
                int i = 0;
                while(current->get_next()!=0 && i<index-1){
                    current = current->get_next();
                    i++;
                }
                newnode->set_next(current->get_next());
                current->set_next(newnode);
                size++;
            }
        }

        void delete_at_head(){
           
		    if(head!=0){
                node<t> *current;
                current = head;
                head = head->get_next();
                delete current;
                size--;
                }
        }

        void delete_at_tail(){
          
		    if(head!=0){
                node<t> *current;
                node<t> *temp;
                current = head;
                while(current->get_next()!=0){
                    temp = current;
                    current = current->get_next();
                }
                temp->set_next(0);
                tail = temp;
                delete current;
                size--;
            }
        }

        void delete_at_index(int index){
        
		    node<t> *current;
            node<t> *temp;
            current = head;
            if(index >= size){
                cout << "This index does not exist!";
            }

            else if(index == size-1){
                delete_at_tail();
            }

            else if(index == 0){
                delete_at_head();
            }

            else{
                int i=0;
                temp = head;
                while(current->get_next()!=0 && i<index){
                    temp = current;
                    current = current->get_next();
                    i++;
                }
                temp->set_next(current->get_next());
                delete current;
                size--;
            }

        }
	
        t& operator[](int index){
          
		    if(index > size-1){
            }
            else{
                node<t> *current;
                current = head;
                while(current!=0 && index-- > 0){
                    current = current->get_next();
                }

                return current->get_data();
            }

        }

        ~sll(){
            delete_list();
        }

};

/* This template Queue class, based on Singly linked List class named as ssl, is used for
storing class File's objects at run time */
template<class t>
class sll_queues{
	
	private:
	
		sll<t>l_queues;
		
	public:
	
		sll_queues(){}
		
		~sll_queues(){}
		
		void enqueue(t data){
			
			l_queues.insert_at_tail(data);
		
		}
		
		t dequeue(){
		
			if(l_queues.get_size() != 0){
				t temp = l_queues[0];
				l_queues.delete_at_head();
				return temp;	
			}else{
				cout << "Queue is empty!" << endl;
			}
		}
		
		int getsize(){
		
			return l_queues.get_size();
	
		}
		
		bool is_empty(){
		
			return (l_queues.get_size()==0);
	
		}
		
		t& front(){
		
			return l_queues[0];
		
		}
				
		void reverse(){
			l_queues.reverse_list();
		}
			
};

/*class File is used for containg complete information about input file.
This class contains class SentenceList,for storing sentences of file,
and total numbers of Sentences, words, alphabets too*/ 
class File{
	
	public:
	int AlphbetCount, SentenceCount, WordCount;
	string Filename;
	SentenceList sl;

	File(){}
	
	File(string n){
		
		Filename=n;
		AlphbetCount=0;
		WordCount=0;
		SentenceCount=0;
		
		
	}
	
	void analys(int a,int w,int s){
		
		AlphbetCount=a;
		WordCount=w;
		SentenceCount=s;
	
	}
	void sent(string s){
		sl.FillList(s);
	}
	string SearchSen(int n){
		return sl[n];
	}
	void printDetails(){

	cout<<"\n\n\t\t\t\t\t\t File Name: "<<Filename;
	cout<<"\n\n\t\t\t\t\t\t Number Of Alphabets: "<<AlphbetCount;
	cout<<"\n\n\t\t\t\t\t\t Number Of Words: "<<WordCount;
    cout<<"\n\n\t\t\t\t\t\t Number of Sentences: " <<SentenceCount;

	}
	
};

/* Queue's Globle object- So, Our three Main Function can Easily access all the inputted files*/
sll_queues<File> q1; // globle obj

//This Function is used for delay purpose which has used in this project several times
void delay(){

    int i;
    for(i=0;i<4500000;i++);

}

/*Instead of looping delay() function, i also modified delay()'s 
updated version which delay 25 times more than delay()*/
void SecDelay(){
	
    int i;
    for(i=0;i<25;i++){
        delay();
    }
}

//This Function Gives Bold line of Full consoul size,used in title or logo of project
void BoldLine(){
	
	cout<<"\n\t\t";
	for(int i=0;i<129;i++){
		cout<<"\xDB";
	}
	cout<<"\t\t";
}

//This Function return Our Project's Logo or Title
void MainScreen(){
	
	string note="\n\n\n\n\tCaution! \n\tBefore Starting Project, Please make sure that console is in Full Screen.\n\n\t";
	string upperline="\t\t\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb";
	string lowerline="\t\t\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc";
	string author="\n\t\t\xba\t\t\t\t\t  	Muhammad Owais Mushtaq  [18k-1177]           \t\t\t\t\t \xba\n";
	
	for(int i=0; i<note.size();i++){
		cout<<note[i];
		delay();
	}
		system("pause");
	
	
	char s=1;
	system("cls");
	cout<<endl<<endl;
	BoldLine();	
	
	cout<<"\n\t\t\xDB\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\xDB";
	cout<<"\n\t\t\xDB\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\xDB";
	cout<<"\n\t\t\xDB\t"<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<"        "<<s<<s<<s<<"\t\t"<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<"             "<<s<<s<<s<<"\t\t"<<s<<s<<s<<s<<s<<s<<"      "<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<"  "<<s<<s<<s<<s<<"        "<<s<<s<<s<<"\t\xDB";
	cout<<"\n\t\t\xDB\t"<<s<<s<<s<<"     "<<s<<s<<s<<"     "<<s<<s<<s<<" "<<s<<s<<s<<"\t\t"<<s<<s<<s<<"     "<<s<<s<<s<<"          "<<s<<s<<s<<" "<<s<<s<<s<<"\t      "<<s<<s<<s<<"    "<<s<<s<<s<<"    "<<s<<s<<s<<"\t     "<<s<<s<<"\t "<<s<<s<<s<<s<<s<<s<<"      "<<s<<s<<s<<"\t\xDB";
	cout<<"\n\t\t\xDB\t"<<s<<s<<s<<"      "<<s<<s<<s<<"   "<<s<<s<<s<<"   "<<s<<s<<s<<"\t"<<s<<s<<s<<"      "<<s<<s<<s<<"        "<<s<<s<<s<<"   "<<s<<s<<s<<"\t     "<<s<<s<<s<<"      "<<s<<s<<s<<"   "<<s<<s<<s<<"\t\t "<<s<<s<<s<<" "<<s<<s<<s<<"     "<<s<<s<<s<<"\t\xDB";
	cout<<"\n\t\t\xDB\t"<<s<<s<<s<<"     "<<s<<s<<s<<"   "<<s<<s<<s<<"     "<<s<<s<<s<<"\t"<<s<<s<<s<<"     "<<s<<s<<s<<"        "<<s<<s<<s<<"     "<<s<<s<<s<<"\t       "<<s<<s<<s<<"\t    "<<s<<s<<s<<"\t\t "<<s<<s<<s<<"  "<<s<<s<<s<<"    "<<s<<s<<s<<"\t\xDB";
	cout<<"\n\t\t\xDB\t"<<s<<s<<s<<s<<s<<s<<s<<s<<s<<"    "<<s<<s<<s<<"       "<<s<<s<<s<<"\t"<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<"        "<<s<<s<<s<<"       "<<s<<s<<s<<"\t         "<<s<<s<<s<<"\t    "<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<"   "<<s<<s<<s<<"   "<<s<<s<<s<<"   "<<s<<s<<s<<"\t\xDB";
	cout<<"\n\t\t\xDB\t"<<s<<s<<s<<"\t    "<<s<<s<<s<<" "<<s<<s<<s<<s<<s<<s<<s<<" "<<s<<s<<s<<"\t"<<s<<s<<s<<s<<s<<s<<s<<"          "<<s<<s<<s<<" "<<s<<s<<s<<s<<s<<s<<s<<" "<<s<<s<<s<<"\t    "<<s<<s<<s<<"     "<<s<<s<<s<<"\t\t "<<s<<s<<s<<"    "<<s<<s<<s<<"  "<<s<<s<<s<<"\t\xDB";
	cout<<"\n\t\t\xDB\t"<<s<<s<<s<<"\t   "<<s<<s<<s<<" "<<s<<s<<s<<s<<s<<s<<s<<s<<s<<" "<<s<<s<<s<<"\t"<<s<<s<<s<<"   "<<s<<s<<s<<"       "<<s<<s<<s<<" "<<s<<s<<s<<s<<s<<s<<s<<s<<s<<" "<<s<<s<<s<<"     "<<s<<s<<s<<"      "<<s<<s<<s<<"  "<<s<<s<<s<<"\t\t "<<s<<s<<s<<"     "<<s<<s<<s<<" "<<s<<s<<s<<"\t\xDB";
	cout<<"\n\t\t\xDB\t"<<s<<s<<s<<"\t  "<<s<<s<<s<<"             "<<s<<s<<s<<"\t"<<s<<s<<s<<"     "<<s<<s<<s<<"    "<<s<<s<<s<<"             "<<s<<s<<s<<"     "<<s<<s<<s<<"    "<<s<<s<<s<<"   "<<s<<s<<s<<"\t     "<<s<<s<<"\t "<<s<<s<<s<<"      "<<s<<s<<s<<""<<s<<s<<s<<"\t\xDB";                                                              
	cout<<"\n\t\t\xDB\t"<<s<<s<<s<<"\t "<<s<<s<<s<<"               "<<s<<s<<s<<"\t"<<s<<s<<s<<"      "<<s<<s<<s<<"  "<<s<<s<<s<<"               "<<s<<s<<s<<"\t "<<s<<s<<s<<s<<s<<s<<"     "<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<"  "<<s<<s<<s<<"        "<<s<<s<<s<<s<<"\t\xDB";
	cout<<"\n\t\t\xDB\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\xDB";
	cout<<"\n\t\t\xDB\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\xDB";
	cout<<"\n\t\t\xDB\t    "<<s<<s<<s<<s<<s<<"\t"<<s<<s<<s<<s<<s<<"\t  "<<s<<s<<s<<"     "<<s<<s<<s<<"  "<<s<<s<<s<<s<<"\t   "<<s<<s<<s<<"  "<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<"  "<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<"  "<<s<<s<<s<<s<<s<<s<<s<<s<<"\t\t\t\t\xDB";
	cout<<"\n\t\t\xDB\t  "<<s<<s<<s<<"   "<<s<<s<<s<<"   "<<s<<s<<s<<"   "<<s<<s<<s<<"   "<<s<<s<<s<<"     "<<s<<s<<s<<"  "<<s<<s<<s<<s<<s<<s<<"      "<<s<<s<<s<<"  "<<s<<s<<"    "<<s<<s<<"    "<<s<<s<<"  "<<s<<s<<s<<"\t "<<s<<s<<"  "<<s<<s<<s<<"    "<<s<<s<<s<<"\t\t\t\t\xDB";
	cout<<"\n\t\t\xDB\t "<<s<<s<<s<<"\t     "<<s<<s<<s<<"     "<<s<<s<<s<<"  "<<s<<s<<s<<"     "<<s<<s<<s<<"  "<<s<<s<<s<<" "<<s<<s<<s<<"     "<<s<<s<<s<<"        "<<s<<s<<"\t"<<s<<s<<s<<"\t     "<<s<<s<<s<<"     "<<s<<s<<s<<"\t\t\t\xDB";
	cout<<"\n\t\t\xDB\t"<<s<<s<<s<<"\t     "<<s<<s<<s<<"     "<<s<<s<<s<<"  "<<s<<s<<s<<"     "<<s<<s<<s<<"  "<<s<<s<<s<<"  "<<s<<s<<s<<"    "<<s<<s<<s<<"        "<<s<<s<<"\t"<<s<<s<<s<<"\t     "<<s<<s<<s<<"    "<<s<<s<<s<<"\t\t\t\t\xDB";
	cout<<"\n\t\t\xDB\t"<<s<<s<<s<<"\t     "<<s<<s<<s<<"     "<<s<<s<<s<<"  "<<s<<s<<s<<"     "<<s<<s<<s<<"  "<<s<<s<<s<<"   "<<s<<s<<s<<"   "<<s<<s<<s<<"        "<<s<<s<<"\t"<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<"   "<<s<<s<<s<<s<<s<<s<<s<<s<<s<<"\t\t\t\t\xDB";
	cout<<"\n\t\t\xDB\t"<<s<<s<<s<<"\t     "<<s<<s<<s<<"     "<<s<<s<<s<<"  "<<s<<s<<s<<"     "<<s<<s<<s<<"  "<<s<<s<<s<<"    "<<s<<s<<s<<"  "<<s<<s<<s<<"        "<<s<<s<<"\t"<<s<<s<<s<<"\t     "<<s<<s<<s<<s<<s<<s<<"\t\t\t\t\xDB";
	cout<<"\n\t\t\xDB\t "<<s<<s<<s<<"\t     "<<s<<s<<s<<"     "<<s<<s<<s<<"  "<<s<<s<<s<<"     "<<s<<s<<s<<"  "<<s<<s<<s<<"     "<<s<<s<<s<<" "<<s<<s<<s<<"        "<<s<<s<<"\t"<<s<<s<<s<<"\t     "<<s<<s<<s<<"   "<<s<<s<<s<<"\t\t\t\t\xDB";
	cout<<"\n\t\t\xDB\t  "<<s<<s<<s<<"   "<<s<<s<<s<<"   "<<s<<s<<s<<"   "<<s<<s<<s<<"    "<<s<<s<<s<<"   "<<s<<s<<s<<"   "<<s<<s<<s<<"      "<<s<<s<<s<<s<<s<<s<<"        "<<s<<s<<"\t"<<s<<s<<s<<"\t "<<s<<s<<"  "<<s<<s<<s<<"    "<<s<<s<<s<<"\t\t\t\t\xDB";
	cout<<"\n\t\t\xDB\t    "<<s<<s<<s<<s<<s<<"\t"<<s<<s<<s<<s<<s<<"\t     "<<s<<s<<s<<s<<s<<"     "<<s<<s<<s<<"        "<<s<<s<<s<<s<<"        "<<s<<s<<"\t"<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<s<<"  "<<s<<s<<s<<"     "<<s<<s<<s<<"\t\t\t\xDB";
	cout<<"\n\t\t\xDB\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\xDB";
	cout<<"\n\t\t\xDB\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\xDB";
	BoldLine();	
	cout<<endl<<endl;
	cout<<"\t\tBy: \n";
		for(int i=0; i<upperline.size();i++){
		cout<<upperline[i];
		delay();
	}
		for(int i=0; i<author.size();i++){
		cout<<author[i];
		delay();
	}
		for(int i=0; i<lowerline.size();i++){
		cout<<lowerline[i];
		delay();
	}
	cout<<"\n\t\t";
	int i=0;
	while(i<1){
		
        system("color 9");
        SecDelay();
        system("color 1");
        SecDelay();
        system("color 9");
        SecDelay();
        system("color A");
        SecDelay();
        system("color 2");
        SecDelay();
        system("color A");
        SecDelay();
        system("color B");
        SecDelay();
        system("color 3");
        SecDelay();
        system("color B");
        SecDelay();
        system("color C");
        SecDelay();
        system("color 4");
        SecDelay();
        system("color C");
        SecDelay();
        system("color D");
        SecDelay();
        system("color 5");
        SecDelay();
        system("color D");
        SecDelay();
        system("color E");
        SecDelay();
        system("color 6");
        SecDelay();
        system("color E");
        SecDelay();
        system("color F");
       	i++;
    }
  
}

//This Function is used for finding cordinates at console
void gotoxy(int x,int y){
    
	coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
    
}

//This Function return MainMenu's Both Frame: Title and contacts
void Box(int a,int b,int c,int d){
    int i;
    system("cls");
    gotoxy(20,10);

    for (i=a; i<=b; i++)
    {
        gotoxy(i,3);
        printf("\xcd");
        gotoxy(i,5);
        printf("\xcd");
        gotoxy(i,c);
        printf("\xcd");
        gotoxy(i,d);
        printf("\xcd");
    }

    gotoxy(a,3);
    printf("\xc9");
    gotoxy(a,4);
    printf("\xba");
    gotoxy(a,5);
    printf("\xc8");
    gotoxy(b,3);
    printf("\xbb");
    gotoxy(b,4);
    printf("\xba");
    gotoxy(b,5);
    printf("\xbc");

    for(i=c; i<=d; i++)
    {
        gotoxy(a,i);
        printf("\xba");
        gotoxy(b,i);
        printf("\xba");
    }
    gotoxy(a,c);
    printf("\xc9");
    gotoxy(a,d);
    printf("\xc8");
    gotoxy(b,c);
    printf("\xbb");
    gotoxy(b,d);
    printf("\xbc");

}

//This one return tile box for all option of MAINMENU
void HeadingBox(){
		
	 int a=40,b=115;
	 
	for (int i=a; i<=b; i++)
    {
    	
    	//40,115,8,40
        gotoxy(i,3);
        printf("\xcd");
        gotoxy(i,5);
        printf("\xcd");

    }
   
    gotoxy(a,3);
    printf("\xc9");
    gotoxy(a,4);
    printf("\xba");
    gotoxy(a,5);
    printf("\xc8");
    gotoxy(b,3);
    printf("\xbb");
    gotoxy(b,4);
    printf("\xba");
    gotoxy(b,5);
    printf("\xbc");

}

/*This function take file Name from user and then checks number of words, Sentence and alphabets
and then by sepration all the sentences of user inputed file send it to SentenceLise 
(Singly Linked List) through the object of class File and then enqueues this object into sll_queue
(Queue).*/
void FileInsertion(){
	
	string file_name,s="";
	int alphbetCount=0, sentenceCount=0, check=0, wordCount=1;
	string sen, sent, words;
	char ch;
	
	system("cls");
	HeadingBox();
	 gotoxy(70,4);
	cout<<"File Insertion\n";

	ifstream Tfile;

	cout << "\n\n\t\t\t\t\t Please input the file name you want to Process(i.e name.type ): ";
   	cin>>file_name;
   	
	int pos = file_name.find(".");  
	string FileName = file_name.substr(0,pos); // it will give file name without it's inputed type e.g input.txt -> input
   	File objA;
   	
   	if(FileCount==0){
   		
   		objA.Filename=FileName;
	
	   }else{
	   
		for(int i=0;i<FileCount; i++){
			File objB;
			objB=q1.dequeue();
			if(objB.Filename==FileName){
				q1.enqueue(objB);
				cout<<"\n\n\t\t\t\t\t File is already inserted! ";
				SecDelay();
				SecDelay();
				SecDelay();
				SecDelay();
				SecDelay();
				BoxFill();
			}
				q1.enqueue(objB);
		}
				objA.Filename=FileName;   			
   		}
	
   	
	Tfile.open(file_name.c_str());
	if(Tfile.is_open()){
		
		FileCount++;
		cout<<"\n\n\t\t\t\t\t File Insertion has successfully Done!";
		ch = Tfile.get();
   			
    while (ch != EOF){	
    		
    	s=s+ch;
       	ch = Tfile.get();
       
    }

   int j=0,k=1,m=0;
   for(int i=0;i<s.size();i++){
   		
   		k++;
        if (s[i] == '.' || s[i]== '!' || s[i]=='?'|| s[i]==';'){	
        	if(s[i+1]==' ' || s[i+1]=='\n' || s[i+1]!= EOF ){
        		
				if(k>20){
				
        			sentenceCount++;
        			string str= s.substr(j,k);
        			k=0;
        			j=i+1;
        			// Inserting Sentence w.h.o class File's ojb f into linked list named as Sentence List
					objA.sent(str);				        			
        				
				}
			}
        	
        }
        
        if(s[i] >64 && s[i] < 91 || s[i]>96 && s[i] <123){	
		
			alphbetCount++;
			
		}
		
		if(s[i]==' '){
			
			check++;
			wordCount++;	
		}
	}
		
    
	cout<<"\n\n\n\t\t\t\t\t File Summery: ";
	objA.analys(alphbetCount, wordCount, sentenceCount);
	objA.printDetails();
	
	// Enqueueing the obj f of class File into singlylinkedlist base queue
	
	
	q1.enqueue(objA);
 			
			gotoxy(60,23);
			cout<<"             * Main Menu";
           	gotoxy(60,26);
			cout<<"             * Exit";
			curser(2);
		
		}else{
		
			cout<<"\n\n\t\t\t\t\t File does not exist! ";
    		gotoxy(60,23);
			cout<<"             * Main Menu";
           	gotoxy(60,26);
			cout<<"             * Exit";
			curser(2);
			}
			
		Tfile.close();


}

/* This Function Firstly takes user input for suring weither the user is intersted in know any 
espasific file Detail or wishes for Average of all inputed datafiles with project. After know 
if it is Average case it find average of Sentences, words and alphabets on the bases of FileCount-
globle varible, keeps to amount of inserted files or if the it is other case then it shows it details 
easily from file object function printdetails() */
void Analysis(){
	
	int AverageAlphabets=0, AverageWords=0, AverageSentences=0;
	bool check=false;
	string input;
	File f1;
	system("cls");
	HeadingBox();
	gotoxy(70,4);
	cout<<"File Analysis\n";
		
		cout<<"\n\n\t\t\t\t\t Enter File Name: ";
		cout<<"(For File Details Enter File Name OR For Averge of uptill";
		cout<<"\n\n\t\t\t\t\t Inserted Files Enter 'Average'): ";
		cin>>input;
	
		if(FileCount!=0){
		
		if(input=="Average"){
			
			for(int i=0;i<FileCount; i++){
			
				f1=q1.dequeue();
				AverageAlphabets = AverageAlphabets + f1.AlphbetCount;
				AverageAlphabets = AverageAlphabets / FileCount;
				 
				AverageWords = AverageWords + f1.WordCount;
				AverageWords = AverageWords / FileCount;
				
				AverageSentences = AverageSentences + f1.SentenceCount;
				AverageSentences = AverageSentences / FileCount;
				
				q1.enqueue(f1);
			}
			
			cout<<"\n\n\t\t\t\t\t *** Average of updated DataSet attached with Program ***";
			cout<<"\n\n\n\t\t\t\t\t Average of Alphabets: "<<AverageAlphabets;
			cout<<"\n\n\t\t\t\t\t Average of Words: "<<AverageWords;
			cout<<"\n\n\t\t\t\t\t Average of Sentences: "<<AverageSentences;
			
			
		}else{
			
			for(int i=0;i<FileCount; i++){
			
				f1=q1.dequeue();
				if(f1.Filename==input){
					q1.enqueue(f1);
					check =true;
					break;
				}
					q1.enqueue(f1);
			}
			
			if(check==true){
				f1.printDetails();
			}else{
				cout<<"\n\n\t\t\t\t\t The input file name is Not matched from inserted file's names! ";
			}
		}	
	}else
		cout<<"\n\n\t\t\t\t\t Please Insert File First! ";
			gotoxy(60,23);
			cout<<"             * Main Menu";
           	gotoxy(60,26);
			cout<<"             * Exit";
			curser(2);
}

/*This funtion take file name if it exist then take the sentence number and then prints that particular sentense*/
void SearchSentence(){
	
	system("cls");
	HeadingBox();
	gotoxy(70,4);
	cout<<"Search Sentence\n";
	
		string inFN;
		int inNum;
		File f1;
		bool check= false;

		cout<<"\n\n\t\t\t\t\t Enter File Name (i.e Name): ";
		cin>>inFN;
		if(FileCount==0){
			cout<<"\n\n\t\t\t\t\t Please Insert File First! ";
		}else{
	
			for(int i=0;i<FileCount; i++){
			
				f1=q1.dequeue();
				if(f1.Filename==inFN){
					q1.enqueue(f1);
					check =true;
					break;
				}
					q1.enqueue(f1);
			}
			
			if(check==true){
			
				cout<<"\n\n\t\t\t\t\t Enter the number of Sentence: ";
				cin>>inNum;
				if(inNum<=f1.sl.SentenceCount){
					if(inNum>0){
						cout<<f1.SearchSen(inNum-1);
					}else 	
						cout<<"Please Try Again! Index is Starting From 1.";
					
				}else{
					cout<<"\n\n\t\t\t\t\t File Does not contains "<<inNum<<" Sentences!";
				}
		}else
				cout<<"\n\n\t\t\t\t\t The input file name is Not matched from inserted file's names! ";
}
		gotoxy(60,23);
		cout<<"             * Main Menu";
        gotoxy(60,26);
		cout<<"             * Exit";
		curser(2);
}

/*This Function highlights the curser movement by (->)*/
void highlight(int no,int count){
	
	 if (no==4){
      
        gotoxy(60,15);
		cout<<"             * Add File";
		gotoxy(60,18);
		cout<<"             * Analysis";
		gotoxy(60,21);
		cout<<"             * Search Sentence";
		gotoxy(60,24);
		cout<<"             * Exit";
       
        switch (count){
        
		case 1:{
			
            gotoxy(60,15);
			cout<<"->           * Add File";
            break;
			}
        case 2:{
		
           	gotoxy(60,18);
			cout<<"->           * Analysis";
            break;
			}
        case 3:{
            gotoxy(60,21);
			cout<<"->           * Search Sentence";
            break;
        	}
    	case 4:{
		
    		gotoxy(60,24);
    		cout<<"->           * Exit";
    		break;
    		}
		}
		
    }else if(no==2){
    
		gotoxy(60,23);
    	cout<<"             * Main Menu";
		gotoxy(60,26);
		cout<<"             * Exit";
		
		
    	switch (count){
    		
        case 1:{
			
            gotoxy(60,23);
			cout<<"->           * Main Menu";
            break;
			}
        case 2:{
		
           	gotoxy(60,26);
			cout<<"->           * Exit";
            break;
			}
		}
    	
	}
}

/*This function used for cursor movement*/
void curser(int no){
    
	int count=1;
    char ch='0';
    gotoxy(85,15);
    while(1){
        
		switch(ch){
        
		case 80:
            count++;
            if (count==no+1) count=1;
            break;
            
        case 72:
            count--;
            if(count==0) count=no;
            break;
        
		}
        
		highlight(no,count);
        ch=getch();
        if(ch=='\r'){
           
        	if(no==4){	
            
				if (count==1) FileInsertion() ;
                else if(count==2) Analysis();
                else if (count==3) SearchSentence();
				else{
					for(int i=0;i<16; i++){
						cout<<endl;
					}
					exit(0);
				}
                
            }else if(no==2){
            	if(count==1)BoxFill();
            	else{
				
            		for(int i=0;i<16; i++){
						cout<<endl;
					}
            		exit(0);
				}
			}
            
        }
    }
}

/*This Funtion is starting controling all the function from filling the MainMenu boxes to exit from program*/
void BoxFill(){
		
	system("cls");
	Box(40,115,8,40);//a for left, b for width,c for space between both boxes,  d for length
	  gotoxy(70,4);
	cout<<"ParaSen Counter";
		gotoxy(60,15);
		cout<<"             * Add File";
		gotoxy(60,18);
		cout<<"             * Analysis";
		gotoxy(60,21);
		cout<<"             * Search Sentence";
		gotoxy(60,24);
		cout<<"             * Exit";

		curser(4);
		
	
}

//Driver Function
int main(){
	

	MainScreen();
	system("pause");
	BoxFill();
	

	
}



