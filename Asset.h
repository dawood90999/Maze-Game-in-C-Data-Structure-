#pragma once
// DAWOOD HUSSAIN (22i-2410) IBRAHIM KAYANI (22i-2686) SECTION E
void ShiftRED()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_INTENSITY);
} 
void ShiftGREEN()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
}
//Shifter FUnctions Change Console Color For Aesthetics
void ShiftNORMAL()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN);
}
void ShiftORANGE()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN);
}
void ShiftYELLOW()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
}
void ShiftCYAN()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
}
string PrintBoard()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "  \t\t\t\t\t            _________    ____     ____  ___   _____ __  __" << endl;
	cout << " \t\t\t\t\t\t   / ____/   |  / __ \\   / __ \\/   | / ___// / / /" << endl;
	cout << " \t\t\t\t\t\t  / /   / /| | / /_/ /  / / / / /| | \\__ \\/ /_/ /" << endl;
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
	cout << "\t\t\t\t\t\t / /___/ ___ |/ _, _/  / /_/ / ___ |___/ / __  / " << endl;
	cout << "\t\t\t\t\t\t \\____/_/  |_/_/ |_|  /_____/_/  |_/____/_/ /_/  " << endl;
	cout << endl;

	cout << "\t\t\t\t\t-----------------------------------------------------------------" << endl;
	cout << "\t\t\t\t\t|                 !         ENTER YOUR NAME       !              |" << endl;
	cout << "\t\t\t\t\t-----------------------------------------------------------------" << endl;
	string pla;
	cin >> pla;
	cout << endl;
	cout << "\t\t\t\t\t\t-*-*-*-*-*-*-*-*-*-*-" << endl;
	cout << "\t\t\t\t\t\t|      RESUME[R]     |" << endl;
	cout << "\t\t\t\t\t\t-*-*-*-*-*-*-*-*-*-*-" << endl;
	cout << endl;
	cout << "\t\t\t\t\t\t-*-*-*-*-*-*-*-*-*-*-" << endl;
	cout << "\t\t\t\t\t\t|      START [S]     |" << endl;
	cout << "\t\t\t\t\t\t-*-*-*-*-*-*-*-*-*-*-" << endl;
	cout << endl;
	cout << "\t\t\t\t\t\t-*-*-*-*-*-*-*-*-*-*-" << endl;
	cout << "\t\t\t\t\t\t|      MODES [M]     |" << endl;
	cout << "\t\t\t\t\t\t-*-*-*-*-*-*-*-*-*-*-" << endl;
	cout << endl;
	cout << "\t\t\t\t\t\t-*-*-*-*-*-*-*-*-*-*-" << endl;
	cout << "\t\t\t\t\t\t|   LEADERBOARD [L]  |" << endl;
	cout << "\t\t\t\t\t\t-*-*-*-*-*-*-*-*-*-*-" << endl;
	cout << endl;
	cout << "\t\t\t\t\t\t-*-*-*-*-*-*-*-*-*-*-" << endl;
	cout << "\t\t\t\t\t\t|      EXIT [ E]     |" << endl;
	cout << "\t\t\t\t\t\t-*-*-*-*-*-*-*-*-*-*-" << endl;
	return pla;
}
//PRINT THE GAME LOGO USING ASCII ART
class Axis // A Node For REPRESENTING Each Point in MAZE OF THE RACETRACK
{
	friend class MAze;
public:
	char symbol;
	Axis* North; 
	Axis* South;
	Axis* East;
	Axis* West;
	int INDEX; // TO Keep Count of AXIS OF MAZE
	int weight;
	Axis(char c = '.')
	{
		symbol = c;
		North = South = West = East = nullptr;
		INDEX = 0;
		weight = 1;
	}
};
class ListNode // A NODE CLASS FOR LINKEDLIST LATTER USED IN GRAPH FOR ALGORITHM
{
public:
	Axis* Data;
	ListNode* Next;
	ListNode(Axis* data = nullptr)
	{
		Data = data;
		Next = nullptr;
	}
};
class LinkedList
{
	ListNode* Head;
public:
	LinkedList()
	{
		Head = nullptr;
	}

	void Insert(Axis* val)
	{
		ListNode* newnode = new ListNode(val);
		if (Head == nullptr)
		{
			Head = newnode;
		}
		else
		{
			ListNode* current = Head;
			while (current->Next)
			{
				current = current->Next;
			}
			current->Next = newnode;
		}
	}

	ListNode* GetHead()
	{
		return Head;
	}

	Axis* GetAxis(Axis* A)
	{
		ListNode* current = Head;
		while (current)
		{
			if (current->Data == A)
			{
				return current->Data;
			}
			current = current->Next;
		}
		return nullptr;
	}

	void Delete(Axis* val)
	{
		if (Head == nullptr)
		{
			return;
		}
		if (Head->Data == val)
		{
			ListNode* temp = Head;
			Head = Head->Next;
			delete temp;
		}
		else
		{
			ListNode* current = Head;
			while (current->Next != nullptr && current->Next->Data != val)
			{
				current = current->Next;
			}
			if (current->Next != nullptr)
			{
				ListNode* temp = current->Next;
				current->Next = current->Next->Next;
				delete temp;
			}
		}
	}

	void Print()
	{
		ListNode* current = Head;
		while (current)
		{
			cout << current->Data->symbol << "->";
			current = current->Next;
		}
		cout << "nullptr" << endl;
	}
};
class CoinNode // A NODE FOR COINS AND COLLECTABLES
{
public:
	char Data;
	int value;
	CoinNode* Next;
	CoinNode(char data = ' ', int val = 10)
	{
		Data = data;
		value = val;
		Next = nullptr;
	}
};
class CoinList // A LINKEDLIST FOR COLLECING COINS AND COLLECTABLE
{
	CoinNode* Head;
public:
	CoinList()
	{
		Head = nullptr;
	}
	void Insert(char val)
	{
		CoinNode* newnode = new CoinNode(val);
		if (Head == nullptr)
		{
			Head = newnode;
		}
		else
		{
			CoinNode* current = Head;
			while (current->Next)
			{
				current = current->Next;
			}
			current->Next = newnode;
		}
	}
	CoinNode* GetHead()
	{
		return Head;
	}
	int GETSIZE()
	{
		CoinNode* current = Head;
		int Size = 0;
		while (current)
		{
			Size++;
			current = current->Next;
		}
		return Size;
	}

	void Delete(char val)
	{
		if (Head == nullptr)
		{
			return;
		}
		if (Head->Data == val)
		{
			CoinNode* temp = Head;
			Head = Head->Next;
			delete temp;
		}
		else
		{
			CoinNode* current = Head;
			while (current->Next != nullptr && current->Next->Data != val)
			{
				current = current->Next;
			}
			if (current->Next != nullptr)
			{
				CoinNode* temp = current->Next;
				current->Next = current->Next->Next;
				delete temp;
			}
		}
	}
	
	void Print()
	{
		CoinNode* current = Head;
		while (current)
		{

			cout << current->Data << " ";
			current = current->Next;
		}
	}
	
};
class QueueNode // A NODE FOR OBSTACLE QUEUE 
{
public:
	char Data;
	int effect;
	QueueNode* Next;
	QueueNode(char data = ' ', int ef = 8)
	{
		Data = data;
		effect = ef;
		Next = nullptr;
	}
};
class Queue // AN OBSTACLE QUEUE FOR GENERATING RANDOM OBSTACLES
{
private:
	QueueNode* Rear;
	QueueNode* Front;
public:
	Queue()
	{
		Front = nullptr;
		Rear = nullptr;
	}
	bool IsEmpty()
	{
		return (Front == nullptr);
	}
	void enqueue(char val)
	{
		QueueNode* newnode = new QueueNode(val);
		if (IsEmpty() == 1)
		{
			Front = Rear = newnode;
		}
		else
		{
			Rear->Next = newnode;
			Rear = newnode;
		}
	}
	char dequeue()
	{
		if (IsEmpty() == 1)
		{
			return '.';
		}
		QueueNode* temp = Front;
		Front = Front->Next;
		char ch = temp->Data;
		delete temp;
		if (Front == nullptr)
		{
			Rear = nullptr;
		}
		return ch;
	}
};
class MAze // THE CORE OF GAME AND VISUAL REPRESNTATION OF MAP
{
	int Vertice;
	Axis** Edges;
	Queue OBSTACLES;
	friend class Graph;
public:
	Axis* Player;
	CoinList* COINS;
	MAze(int n)
	{
		Vertice = n;
		Edges = new Axis * [n];
		for (int k = 0; k < n; k++)
		{
			Edges[k] = new Axis[n];
		}
		int in = 1;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				Edges[i][j].INDEX = in;
				in++;
			}
		}
		for (int j = 0; j < Vertice; j++)
		{
			OBSTACLES.enqueue('#');
		}
		COINS = new CoinList();
		connectNodes();
		InitializeMaze(n);
	}
	void GenerateOBSTACLE()
	{
		int i = rand() % Vertice;
		int f = rand() % Vertice;
		if (Edges[i][f].symbol == '.')
		{
			Edges[i][f].symbol = OBSTACLES.dequeue();
		}
	} // GENEATE ONE OBSTACLE WHEN CALLED AT RANDOM POSITION
	void InitializeWalls(int n)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i % 2 == 0)
				{
					Edges[j][i].symbol = '|';
				}
			}
		}
		for (int i = 0; i < n-2; i++)
		{
			int j = rand() % n;
			Edges[i][j].symbol = '.';
			do
			{
				j = rand() % n;
			} while (Edges[i][j].symbol == '.');

			Edges[i][j].symbol = '.';
		}
	} //GENERATE WALLS IN EVEN COLUMNS AND GIVE OPENINGS AT RANDOM POINT IN THOSE COLUMNS 
	void InitializeCollectable(int n)
	{
		for (int i = 0; i < n; i++)
		{
			int f = rand() % n;
			Edges[i][f].symbol = 'o';
		}
		for (int i = 0; i < n/2; i++)
		{
			if (i % 2 == 1) 
			{
				int f = rand() % n;
				Edges[i][f].symbol = '?';
			}
			}
		for (int i = n / 2; i < n / 2 + 2; i++)
		{
			int j = rand() % n;
			Edges[i][j].symbol = '*';
			j = rand() % n;
			Edges[i][j].symbol = '~';
		}
	} //INITIALIZE COINS AND COLLECTABLE IN RANDOM LOCATIONS ON MAP
	void InitializeMaze(int n)
	{
		srand(time(0));
		InitializeWalls(n);
		InitializeCollectable(n);
		Edges[n - 1][n - 1].symbol = 'F';
		Player = &Edges[0][1];
		Player->symbol = 'C';
		for (int i = 0; i < Vertice; i++)
		{
			for (int j = 0; j < Vertice; j++)
			{
				if (IsPivot(Edges[i][j]) == 1)
				{
					if (Edges[i][j].symbol == '.')
					{
						Edges[i][j].symbol = '+';
					}

				}
			}
		}
	} //INITIALIZE START AND END POINT FOR THE PLAYER
	bool IsPivot(Axis A)
	{
		bool flag = false;
		if (A.North && A.East)
		{
			if (A.North->symbol == '.' && A.East->symbol == '.')
			{
				flag = true;
			}
		}
		else
			if (A.North && A.West)
			{
				if (A.North->symbol == '.' && A.West->symbol == '.')
				{
					flag = true;
				}
			}
			else
				if (A.South && A.East)
				{
					if (A.South->symbol == '.' && A.East->symbol == '.')
					{
						flag = true;
					}
				}
				else
					if (A.South && A.West)
					{
						if (A.South->symbol == '.' && A.West->symbol == '.')
						{
							flag = true;
						}
					}
		return flag;
	} //CHECK IF THE AXIS POINT IS PIVOT MEANING WHETHER IT HAS 2 DIRECTIONS OR ONE
	void connectNodes()
	{
		for (int i = 0; i < Vertice; i++)
		{
			for (int j = 0; j < Vertice; j++)
			{
				Axis* node = &Edges[i][j];

				if (i > 0 && Edges[i - 1][j].symbol == '.')
				{
					node->North = &Edges[i - 1][j];
				}
				if (i < Vertice - 1 && Edges[i + 1][j].symbol == '.')
				{
					node->South = &Edges[i + 1][j];
				}
				if (j > 0 && Edges[i][j - 1].symbol == '.')
				{
					node->West = &Edges[i][j - 1];
				}
				if (j < Vertice - 1 && Edges[i][j + 1].symbol == '.')
				{
					node->East = &Edges[i][j + 1];
				}
			}
		}
	} //A FUNCTION TO INTERCONNECT NODES OF THE MAZE
	int GetRowindex()
	{
		for (int i = 0; i < Vertice; i++)
		{
			for (int j = 0; j < Vertice; j++)
			{
				if (Edges[i][j].symbol == '~')
				{
					return j;
				}
			}
		}
		return Vertice / 2;
	}
	void PrintMaze()
	{
		HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
		for (int i = 0; i < Vertice; i++)
		{
			cout << "\t\t\t\t\t\t";
			for (int j = 0; j < Vertice; j++)
			{
				if (Edges[i][j].symbol == '#')
				{
					SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				}
				else
					if (Edges[i][j].symbol == '|')
					{
						SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					}
					else
						if (Edges[i][j].symbol == 'o')
						{
							ShiftYELLOW();
						}
						else
							if (Edges[i][j].symbol == '.' || Edges[i][j].symbol == '*')
							{
								SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_RED);
							}
							else
								if (Edges[i][j].symbol == 'F' || Edges[i][j].symbol == 'C')
								{
									SetConsoleTextAttribute(console, FOREGROUND_GREEN );
								}
								else
									if (Edges[i][j].symbol == '+')
									{
										SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
									}
									else
										if (Edges[i][j].symbol == '~')
										{
											SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_RED);
										}
										else if (Edges[i][j].symbol == '?')
										{
											ShiftORANGE();
										}
				cout << Edges[i][j].symbol << " ";
			}
			cout << endl;
		}
		SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
	} //PRINT THE VISUAL REPRESNATATION OF MAZE
	void Swap(Axis& current, Axis& next, int& SCORE, int& SHIELD)
	{
		if (next.symbol == '|')
		{
			return;
		}
		if (next.symbol == '+')
		{
			SHIELD++;
			next.symbol = '.';
		}
		char temp = next.symbol;
		next.symbol = current.symbol;
		current.symbol = temp;
		Player = &next;
		SCORE = SCORE + 1;
	}//SWAP THE 2 AXIS AND UPDATE PLAYER MOSTLY USED FOR MOVEMENT
	bool UPDATER(Axis*& NODE, int& SCORE, int& HEALTH,int& SHEILD)
	{
		if (NODE->symbol == 'F')
		{
			return 1;
		}
		else
			if (NODE->symbol == '#')
			{
				if (SHEILD >= 5) 
				{
					NODE->symbol = '.';
					SHEILD = SHEILD - 5;
					return 0;
				}
				HEALTH--;
				SCORE = SCORE - 2 - 25;
				NODE->symbol = '.';
			}
			else
				if (NODE->symbol == 'o')
				{
					COINS->Insert('o');
					SCORE = SCORE + 8;
					NODE->symbol = '.';
				}
				else
					if (NODE->symbol == '~')
					{
						int g = GetRowindex();
						for (int i = 0; i < Vertice; i++)
						{
							if (Edges[g][i].symbol == '|')
								Edges[g][i].symbol = '.';
						}
						NODE->symbol = '.';
					}
					else
						if (NODE->symbol == '*')
						{
							SCORE = SCORE * 2;
							NODE->symbol = '.';
						}

						else
							if (NODE->symbol == '?')
							{
								srand(time(0));
								int a = rand() % 3;
								if (a==0) 
								{
									COINS->Insert('@');
								}
								if (a == 1)
								{
									COINS->Insert('%');
								}
								if (a == 2)
								{
									COINS->Insert('$');
								}
								NODE->symbol = '.';
							}
		return 0;
	} //APPLIES EFFECT BASED ON THE CHAR VALUE OF AXIS BEFORE SWAPPING THEM
	bool Animate(char s, int& SCORE,int& HEALTH,int& SHIELD)
	{
		int a = s;
		bool flag = false;
		if (a == 119)
		{
			if (Player->North)
			{
				flag = UPDATER(Player->North, SCORE, HEALTH,SHIELD);
				if (flag)
				{
					return 1;
				}
				Swap(*Player, *Player->North, SCORE,SHIELD);

			}
		}
		if (a == 115)
		{
			if (Player->South)
			{
				flag = UPDATER(Player->South, SCORE, HEALTH, SHIELD);
				if (flag)
				{
					return 1;
				}
				Swap(*Player, *Player->South, SCORE,SHIELD);
			}
		}
		if (a == 97)
		{
			if (Player->West)
			{
				flag = UPDATER(Player->West, SCORE, HEALTH, SHIELD);
				if (flag)
				{
					return 1;
				}
				Swap(*Player, *Player->West, SCORE, SHIELD);

			}
		}
		if (a == 100)
		{
			if (Player->East)
			{
				flag = UPDATER(Player->East, SCORE, HEALTH, SHIELD);
				if (flag)
				{
					return 1;
				}
				Swap(*Player, *Player->East, SCORE, SHIELD);
			}
		}
		GenerateOBSTACLE();
		return 0;
	}// A CORE FUNCTIONALITY WHERE THE ANIMATION I.E. SWAPPING AND UPDATING IS CALLED
	Axis* GetAxis(int index)
	{
		for (int i = 0; i < Vertice; i++)
		{
			for (int j = 0; j < Vertice; j++)
			{
				if (Edges[i][j].INDEX == index)
				{
					return &Edges[i][j];
				}
			}
		}
		return nullptr;
	}
	void StoreMaze(int HEALTH, int SHEILD,int coins,int score)
	{
		ofstream file("Maze.txt");
		file << Vertice << endl;
		file << HEALTH << endl;
		file << SHEILD << endl;
		file << coins << endl;
		file << score << endl;
		file << Player->INDEX << endl;
		for (int i = 0; i < Vertice; i++)
		{
			cout << "\t\t\t\t\t\t";
			for (int j = 0; j < Vertice; j++)
			{
				file << Edges[i][j].symbol << " ";
			}
		

		}
	}
	//Store Entire maze in a file to restore for resuming a game
	void UpdateMaze() 
	{
		Player->symbol = '.';
		ifstream file("Maze.txt");
		string key;
		getline(file, key);
		getline(file, key);
		getline(file, key);
		getline(file, key);
		getline(file, key);
		getline(file, key);
		int a = stoi(key);
		Player->symbol = '.';
		int i = 0, j = 0;
		while (getline(file,key)) 
		{
			stringstream SS(key);
			string cell;
			while (getline(SS,cell,' '))
			{
				char c = cell[0];
				if (c == 'F'|| c=='C')
				{
					c = '.';
				}
				*&Edges[i][j].symbol = c ;
				if(i<Vertice-1)
				i++;
			}
			if (j < Vertice-1)
			j++;
		}
		GetAxis(a)->symbol = 'C';
		Player = GetAxis(a);
		file.close();
	}
	//READ Entire maze from a file to restore for resuming a game
	void CLeanMaze() 
	{
		ofstream file("Maze.txt");
		file << "-" << endl;
		file << "-" << endl;
		file << "-" << endl;
		file << "-" << endl;
		file << "-" << endl;
		file << "-" << endl;
		file << "-" << endl;
		file.close();
	}
};
struct Node {
	string Name;
	string SCORE;
	string coins;
	string status;
	Node* left;
	Node* right;

	Node(string n = "", string s = "", string coin = "", string stat = "")
	{
		Name = n;
		SCORE = s;
		coins = coin;
		status = stat;
		left = nullptr;
		right = nullptr;
	}
};//NODE FOR STORING RESULTS IN BST TREE (FILE HANDLING PURPOSE)
class SCORETREE {
private:
	Node* root;
	Node* InsertData(Node* node, string name, string score, string coins, string stat) 
	{
		if (node == nullptr) 
		{
			return new Node(name, score, coins, stat);
		}
		int newScore = stoi(score);
		int currentScore = stoi(node->SCORE);
		if (newScore < currentScore) 
        {
			node->left = InsertData(node->left, name, score, coins, stat);
		}
		else if (newScore > currentScore) 
		{
			node->right = InsertData(node->right, name, score, coins, stat);
		}
		return node;
	}
	void InorderTraversal(Node* root) {
		static int i = 1;
		ShiftNORMAL();
		if (root != nullptr)
		{
			InorderTraversal(root->right);

			cout << "\t" ;
			ShiftCYAN();
			cout << root->Name << "\t\t\t\t";
			cout << root->SCORE << "\t\t\t ";
			if (root->status =="WON")
			{
				ShiftGREEN();

			}
			else 
			{
				ShiftRED();
			}
			cout << root->status << "\t\t\t ";
			ShiftYELLOW();
			cout<< root->coins << "\t\t   ";
			ShiftRED();
			cout << i++ << endl;
			InorderTraversal(root->left);
			ShiftNORMAL();
		}
	}

public:
	SCORETREE()
	{
		root = nullptr;
	}

	void insert(string name, string score, string coin, string stat)
	{
		root = InsertData(root, name, score, coin, stat);
	}
	void inorder()
	{
		InorderTraversal(root);
		cout << endl;
	}

	void DeleteNodes(Node* node)
	{
		if (node)
		{
			DeleteNodes(node->left);
			DeleteNodes(node->right);
			delete node;
		}
	}
};
class Graph
{
private:
	int vertices;
	LinkedList** Edge;
	MAze* MAZE;
public:
	Graph(MAze* maze)
	{
		vertices = maze->Vertice* maze->Vertice;
		MAZE = maze;
		Edge = new LinkedList * [vertices];
		for (int i = 0; i < vertices; i++)
		{
			Edge[i] = new LinkedList[vertices];
		}
		GenerateGraph();
	}
	void AddEdge(Axis* source, Axis*& target)
	{
		Edge[source->INDEX - 1]->Insert(target);
		Edge[target->INDEX - 1]->Insert(source);
	} // ADD EDGES OF THE GRAPH
	int getvert()
	{
		return vertices;
	}
	void PrintGraph()
	{
		for (int i = 0; i < vertices; ++i)
		{
			cout << "Vertex " << i << ": ";
			Edge[i]->Print();
		}
	}
	void GenerateGraph()
	{
		for (int i = 0; i < MAZE->Vertice; ++i)
		{
			for (int j = 0; j < MAZE->Vertice; ++j)
			{
				Axis* currentNode = &MAZE->Edges[i][j];
				if (currentNode->symbol != '|')
				{
					if (currentNode->North && currentNode->North->symbol != '|')
					{
						AddEdge(currentNode, currentNode->North);
					}

					if (currentNode->South && currentNode->South->symbol != '|')
					{
						AddEdge(currentNode, currentNode->South);
					}

					if (currentNode->East && currentNode->East->symbol != '|')
					{
						AddEdge(currentNode, currentNode->East);
					}

					if (currentNode->West && currentNode->West->symbol != '|')
					{
						AddEdge(currentNode, currentNode->West);
					}
				}
			}
		}
	}
	void MoveCarAlongShortestPath(Axis* end, int& SCORE,int& SHIELD)
	{
		while (true)
		{
			if (MAZE->Player->East && MAZE->Player->East->symbol != '|')
			{
				if (MAZE->Player->East->symbol == 'F')
				{
					cout << "\t\t\t-----------------------------------------------------------------" << endl;
					cout << "\t\t\t|                                                               |" << endl;
					cout << "\t\t\t|                 !         ENDED           !                   |" << endl;
					cout << "\t\t\t|                                                               |" << endl;
					cout << "\t\t\t-----------------------------------------------------------------" << endl;
					break;
				}
				MAZE->Player->East->symbol = '@';
				MAZE->Swap(*MAZE->Player, *MAZE->Player->East, SCORE, SHIELD);
			}
			else if (MAZE->Player->South && MAZE->Player->South->symbol != '|')
			{
				if (MAZE->Player->South->symbol == 'F')
				{
					cout << "\t\t\t-----------------------------------------------------------------" << endl;
					cout << "\t\t\t|                                                               |" << endl;
					cout << "\t\t\t|                 !         ENDED           !                   |" << endl;
					cout << "\t\t\t|                                                               |" << endl;
					cout << "\t\t\t-----------------------------------------------------------------" << endl;
					break;
				}
				MAZE->Player->South->symbol = '@';
				MAZE->Swap(*MAZE->Player, *MAZE->Player->South, SCORE, SHIELD);
			}
			else if (MAZE->Player->North && MAZE->Player->North->symbol != '|')
			{
				if (MAZE->Player->North->symbol == 'F') 
				{
					cout << "\t\t\t-----------------------------------------------------------------" << endl;
					cout << "\t\t\t|                                                               |" << endl;
					cout << "\t\t\t|                 !         ENDED           !                   |" << endl;
					cout << "\t\t\t|                                                               |" << endl;
					cout << "\t\t\t-----------------------------------------------------------------" << endl;
					break;
				}
				while (MAZE->Player->East->symbol == '|'&& MAZE->Player->North)
				{
					if (MAZE->Player->North->symbol == '@') 
					{
						MAZE->Player->North->symbol = '.';
					}
					else 
					{
						MAZE->Player->North->symbol = '@';
					}
				 	MAZE->Swap(*MAZE->Player, *MAZE->Player->North, SCORE, SHIELD);
				   if( !MAZE->Player->East  && (MAZE->Player->South->symbol=='|' && MAZE->Player->North->symbol == '|'))
				   {
					   MAZE->Player->West->symbol = '@';
					MAZE->Swap(*MAZE->Player, *MAZE->Player->West, SCORE, SHIELD);
				   }
				}
				
			}
			else
			{
				break;
			}
			system("cls");
			cout << "SCORE = " << SCORE << endl;
			MAZE->PrintMaze();
		}

	}//ALGORITHM FOR SHORTEST PATH (CUSTOM)

};
