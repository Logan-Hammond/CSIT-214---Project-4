
//arrays for airline problem

const int ROW = 9;
const int COL = 4;
const int CTR = 3;

//initial seats in the plane
	char layout[ROW][COL] = {  { 'A', 'B', 'C', 'D' },
							{ 'A', 'B', 'C', 'D' },
							{ 'A', 'B', 'C', 'D' },
							{ 'A', 'B', 'C', 'D' },
	                        { 'A', 'B', 'C', 'D' },
	                        { 'A', 'B', 'C', 'D' },
	                        { 'A', 'B', 'C', 'D' },
							{ 'A', 'B', 'C', 'D' },
							{ 'A', 'B', 'C', 'D' }};

	int classCtr[CTR] = {0,0,0};

	std::string classes[] = {"First Class", "Business Class", "Coach"};

	double fare [] = {500, 300, 100};