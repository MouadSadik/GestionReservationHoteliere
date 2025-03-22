struct date
{
	unsigned int j ;
	unsigned int m ;
	unsigned int a ;
};
typedef struct date Date ;

int IsDate(unsigned int, unsigned int, unsigned int) ;
int IsStrDate(char * , const char );
int ComparerDatesCroissantes(Date, Date) ;
int ComparerDatesDecroissantes(Date, Date) ;
