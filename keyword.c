#define MAX_NAME 30
#define N_KEYS	14 


struct keytab {
	
	int nums;		//몇번 나오는지
	char name[MAX_NAME];	
};

struct keytab keywrds[N_KEYS] = {
	
	{0,"int"},
	{0,"float"},
	{0, "return"},
	{0, "if"},
	{0, "for"},
	{0, "while"},
	{0, "goto"},
	{0, "switch"},
	{0, "case"},
	{0, "void"},
	{0, "default"},
	{0, "char"},
	{0, "do"},
	{0, "scanf"}		//0은 몇번 나왔나 세는 것 
};

void count_word(char *word) {
	
	int i;
	//for each keywords
	for(i=0;i<N_KEYS;i++)
	{
		//if word= #i keyword
		if(strncmp(word, keywrds[i].name, strlen(keywrds[i].name))==0)			//string을 10개까지 비교 
		{	//nums++
			keywrds[i].nums++;
		}
	}
}

void print_word() {
	
	int i;
	//#i keyword
	for(i=0;i<N_KEYS;i++)
	{	//printf("keyword name : count);
		printf("%s : %i\n", keywrds[i].name, keywrds[i].nums);
	}
}
