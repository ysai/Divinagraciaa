#include "Project.h"
int day,month,year;
#define MAX	200000
#define LL	long long
#define LIMIT	1000
bool composite[MAX + 1];
vector<int> primes;
Project::Project()
{

}

Project::~Project()
{

}

void Project::multiples_of_3_and_5(){
    int numbers[1000];
    int store=0;

    for(int i=0; i<999; i++){
        numbers[i] = i+1;
    }

    for(int a=0; a<999; a++){
        if (numbers[a]%3==0 || numbers[a]%5==0){
            store = store+numbers[a];
    }
}
cout <<"The sum of all multiples of 3 and 5 below 1000 is: " <<store<<endl;
}

void Project::even_fibonacce(){
    int fibo=2;
    int array[100];
    array[0]=1;
    array[1]=2;
    for(int i=2; fibo<4000000; i++){
        array[i]=array[i-1]+array[i-2];
        if(array[i]%2==0 && array[i]<4000000)
            fibo=array[i]+fibo;
  }
    cout << "The Sum of the even valued terms is: "<< fibo << endl;

}

void Project::largest_prime_factor(){
    long long largest_prime_factor=0;
    long long target=600851475143LL;

    for(int i = 3; i<round(sqrt(target)); i+=2){
        if (Prime_check(i))
            {
                if (target % i == 0 && i > largest_prime_factor)
                {
                    largest_prime_factor = i;
                }
            }

    }cout << "The largest prime factor of 600851475143 is: " << largest_prime_factor << endl;
}
void Project::largest_palindrome_product(){
    int a,b,palinProduct=0,a1,b1;
    long long x;
    char toChar[20];
    string Str,revStr;

    for(a=100; a<1000; a++){
        for(b=100; b<1000; b++){
            x = a*b;
            itoa(x,toChar);
            Str = toChar;
            reverse(toChar);
            revStr = toChar;
            if(Str==toChar&&x>palinProduct){
                palinProduct=x;
                a1=a;
                b1=b;
            break;}
        }
    }
    cout<< "The largest palindrome product of two 3-digit numbers is: "<< palinProduct
    << "\nThe two 3-digit numbers are "<< a1 << " and "<< b1 <<endl;
}

void Project::itoa(int n, char s[])
 {
     int i, sign;
     if ((sign = n) < 0)
         n = -n;
     i = 0;
     do {
         s[i++] = n % 10 + '0';
     } while ((n /= 10) > 0);
     if (sign < 0)
     s[i++] = '-';
     s[i] = '\0';
     reverse(s);
 }

 void Project::reverse(char s[])
 {
     int i, j;
     char c;

     for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
         c = s[i];
         s[i] = s[j];
         s[j] = c;
     }
 }


void Project::smallest_multiple(){
    int multiple=0;
    for(int i=1; i<300000000; i++){
        if(i%2==0&&i%3==0&&i%4==0&&i%5==0&&i%6==0&&i%7==0&&i%8==0&&i%9==0&&i%10==0&&
           i%11==0&&i%12==0&&i%13==0&&i%14==0&&i%15==0&&i%16==0&&i%17==0&&i%18==0
           &&i%19==0&&i%20==0){
        multiple = i;
        break;}
    }
    cout << "The smallest multiple of numbers 1-20 is: " << multiple << endl;
}

void Project::sum_square_difference(){
    int sum_of_squares=0,square_of_sum=0,difference=0;
    int array[100];
    int temp=0;
    for(int i=0; i<100; i++){
        array[i]=i+1;
       }
    for(int a=0; a<100; a++){
        sum_of_squares = pow(array[a],2) + sum_of_squares;
        }
    for(int b=0; b<100; b++){
        temp=array[b]+temp;
        if(b==99)
        square_of_sum=pow(temp,2);}
    difference=square_of_sum-sum_of_squares;
    cout << "The difference is: " << difference << endl;

}

void Project::_10001st_prime(){
    int factor_number=2;
    int i,answer;

    for(i=5; factor_number!=10001; i+=2){
        if(Prime_check(i)){
            factor_number+=1;
            if(factor_number==10001)
            answer=i;
        }
    }
    cout << "The 10001st Prime is: " << answer << endl;
}

void Project::largest_product_in_a_series(){
    int temp=0;
    int array[1000]={
    7,3,1,6,7,1,7,6,5,3,1,3,3,0,6,2,4,9,1,9,2,2,5,1,1,9,6,7,4,4,2,6,5,7,4,7,4,2,3,5,5,3,4,9,1,9,4,9,3,4,
    9,6,9,8,3,5,2,0,3,1,2,7,7,4,5,0,6,3,2,6,2,3,9,5,7,8,3,1,8,0,1,6,9,8,4,8,0,1,8,6,9,4,7,8,8,5,1,8,4,3,
    8,5,8,6,1,5,6,0,7,8,9,1,1,2,9,4,9,4,9,5,4,5,9,5,0,1,7,3,7,9,5,8,3,3,1,9,5,2,8,5,3,2,0,8,8,0,5,5,1,1,
    1,2,5,4,0,6,9,8,7,4,7,1,5,8,5,2,3,8,6,3,0,5,0,7,1,5,6,9,3,2,9,0,9,6,3,2,9,5,2,2,7,4,4,3,0,4,3,5,5,7,
    6,6,8,9,6,6,4,8,9,5,0,4,4,5,2,4,4,5,2,3,1,6,1,7,3,1,8,5,6,4,0,3,0,9,8,7,1,1,1,2,1,7,2,2,3,8,3,1,1,3,
    6,2,2,2,9,8,9,3,4,2,3,3,8,0,3,0,8,1,3,5,3,3,6,2,7,6,6,1,4,2,8,2,8,0,6,4,4,4,4,8,6,6,4,5,2,3,8,7,4,9,
    3,0,3,5,8,9,0,7,2,9,6,2,9,0,4,9,1,5,6,0,4,4,0,7,7,2,3,9,0,7,1,3,8,1,0,5,1,5,8,5,9,3,0,7,9,6,0,8,6,6,
    7,0,1,7,2,4,2,7,1,2,1,8,8,3,9,9,8,7,9,7,9,0,8,7,9,2,2,7,4,9,2,1,9,0,1,6,9,9,7,2,0,8,8,8,0,9,3,7,7,6,
    6,5,7,2,7,3,3,3,0,0,1,0,5,3,3,6,7,8,8,1,2,2,0,2,3,5,4,2,1,8,0,9,7,5,1,2,5,4,5,4,0,5,9,4,7,5,2,2,4,3,
    5,2,5,8,4,9,0,7,7,1,1,6,7,0,5,5,6,0,1,3,6,0,4,8,3,9,5,8,6,4,4,6,7,0,6,3,2,4,4,1,5,7,2,2,1,5,5,3,9,7,
    5,3,6,9,7,8,1,7,9,7,7,8,4,6,1,7,4,0,6,4,9,5,5,1,4,9,2,9,0,8,6,2,5,6,9,3,2,1,9,7,8,4,6,8,6,2,2,4,8,2,
    8,3,9,7,2,2,4,1,3,7,5,6,5,7,0,5,6,0,5,7,4,9,0,2,6,1,4,0,7,9,7,2,9,6,8,6,5,2,4,1,4,5,3,5,1,0,0,4,7,4,
    8,2,1,6,6,3,7,0,4,8,4,4,0,3,1,9,9,8,9,0,0,0,8,8,9,5,2,4,3,4,5,0,6,5,8,5,4,1,2,2,7,5,8,8,6,6,6,8,8,1,
    1,6,4,2,7,1,7,1,4,7,9,9,2,4,4,4,2,9,2,8,2,3,0,8,6,3,4,6,5,6,7,4,8,1,3,9,1,9,1,2,3,1,6,2,8,2,4,5,8,6,
    1,7,8,6,6,4,5,8,3,5,9,1,2,4,5,6,6,5,2,9,4,7,6,5,4,5,6,8,2,8,4,8,9,1,2,8,8,3,1,4,2,6,0,7,6,9,0,0,4,2,
    2,4,2,1,9,0,2,2,6,7,1,0,5,5,6,2,6,3,2,1,1,1,1,1,0,9,3,7,0,5,4,4,2,1,7,5,0,6,9,4,1,6,5,8,9,6,0,4,0,8,
    0,7,1,9,8,4,0,3,8,5,0,9,6,2,4,5,5,4,4,4,3,6,2,9,8,1,2,3,0,9,8,7,8,7,9,9,2,7,2,4,4,2,8,4,9,0,9,1,8,8,
    8,4,5,8,0,1,5,6,1,6,6,0,9,7,9,1,9,1,3,3,8,7,5,4,9,9,2,0,0,5,2,4,0,6,3,6,8,9,9,1,2,5,6,0,7,1,7,6,0,6,
    0,5,8,8,6,1,1,6,4,6,7,1,0,9,4,0,5,0,7,7,5,4,1,0,0,2,2,5,6,9,8,3,1,5,5,2,0,0,0,5,5,9,3,5,7,2,9,7,2,5,
    7,1,6,3,6,2,6,9,5,6,1,8,8,2,6,7,0,4,2,8,2,5,2,4,8,3,6,0,0,8,2,3,2,5,7,5,3,0,4,2,0,7,5,2,9,6,3,4,5,0
    };

    for(int i=0; i<1000; i++){
        if(array[i]*array[i+1]*array[i+2]*array[i+3]*array[i+4]>temp){
            temp=array[i]*array[i+1]*array[i+2]*array[i+3]*array[i+4];}
    }
    cout << "The Highest Product is: " << temp << endl;


}


void Project::special_pytho_triplet(){
    int sum;
    int product_abc=0;
    int array[1001];
    for(int i=1; i<1001; i++){
        array[i]=i;
    }
    for(int k=1; k<1001; k++){
        for(int j=1; j<1001-k; j++){
            for(int h=1; h<1001-(k+j); h++){
                sum=array[k]+array[k+j]+array[k+j+h];
                if(sum==1000&&pow(array[k],2)+ pow(array[k+j],2)==pow(array[k+j+h],2)){
                    product_abc=array[k]*array[k+j]*array[k+j+h];
                    break;}
                sum=0;
            }
        }

    }
    cout << "The Product of abc is: " << product_abc << endl;
}

void Project::summation_of_prime(){
    long long temp2=5;

    for(int a=5; a<2000000; a+=2){
        if(Project::Prime_check(a)){
            temp2+=a;
        }
    }
    cout << "The sum of all primes below 2Million is: " << temp2 << endl;
}

bool Project::Prime_check(long num){
     bool Prime_check = true;
     for (int i=2; i<= round(sqrt(num)) && Prime_check; i++)
     {
         Prime_check = !(num % i == 0);
     }
     return Prime_check;
}

void Project::largest_product_in_grid(){

int num_container[20][20] =
{
{ 8,02,22,97,38,15,00,40,00,75,04,05,07,78,52,12,50,77,91, 8},
{49,49,99,40,17,81,18,57,60,87,17,40,98,43,69,48,04,56,62,00},
{81,49,31,73,55,79,14,29,93,71,40,67,53,88,30,03,49,13,36,65},
{52,70,95,23,04,60,11,42,69,24,68,56,01,32,56,71,37,02,36,91},
{22,31,16,71,51,67,63,89,41,92,36,54,22,40,40,28,66,33,13,80},
{24,47,32,60,99,03,45,02,44,75,33,53,78,36,84,20,35,17,12,50},
{32,98,81,28,64,23,67,10,26,38,40,67,59,54,70,66,18,38,64,70},
{67,26,20,68,02,62,12,20,95,63,94,39,63, 8,40,91,66,49,94,21},
{24,55,58,05,66,73,99,26,97,17,78,78,96,83,14,88,34,89,63,72},
{21,36,23, 9,75,00,76,44,20,45,35,14,00,61,33,97,34,31,33,95},
{78,17,53,28,22,75,31,67,15,94,03,80,04,62,16,14, 9,53,56,92},
{16,39,05,42,96,35,31,47,55,58,88,24,00,17,54,24,36,29,85,57},
{86,56,00,48,35,71,89,07,05,44,44,37,44,60,21,58,51,54,17,58},
{19,80,81,68,05,94,47,69,28,73,92,13,86,52,17,77,04,89,55,40},
{04,52, 8,83,97,35,99,16,07,97,57,32,16,26,26,79,33,27,98,66},
{88,36,68,87,57,62,20,72,03,46,33,67,46,55,12,32,63,93,53,69},
{04,42,16,73,38,25,39,11,24,94,72,18, 8,46,29,32,40,62,76,36},
{20,69,36,41,72,30,23,88,34,62,99,69,82,67,59,85,74,04,36,16},
{20,73,35,29,78,31,90,01,74,31,49,71,48,86,81,16,23,57,05,54},
{01,70,54,71,83,51,54,69,16,92,33,48,61,43,52,01,89,19,67,48},
                                                            };

int start = 0;
int end = 3;
int product = 1;

vector<long int>final_results;

    for(int i=0; i<20; i++){
        for(int j=start; j<=end; j++){
            product=product*num_container[i][j];
            if(j==end){
            final_results.push_back(product);
            product=1;
            start++;
            end++;
            }
            if(j==19)break;
        }
        start=0;
        end=3;
        for(int k=start; k<=end; k++){
            product=product*num_container[k][i];
            if(k==end){
            final_results.push_back(product);
            product=1;
            start++;
            end++;
            }
            if(k==19){
            start=0;
            end=3;
            break;
            }
        }
    }

int current_row = 0;

    for(int i=0; i<=16; i++)
    {
        for(int j=0; j<=16; j++)
        {
            current_row = i;
            for(int k=start; k<=end; k++)
            {
                product = product * num_container[current_row][k];
                current_row++;
                if (k==end)
                    final_results.push_back(product);
            }
            product = 1;
            start++;
            end++;
        }
        start = 0;
        end = 3;

        for(int j=0; j<=16; j++)
        {
            current_row = i+3;
            for(int k=start; k<=end; k++)
            {
                product = product * num_container[current_row][k];
                current_row--;
                if (k==end)
                    final_results.push_back(product);
            }
            product = 1;
            start++;
            end++;
        }
        start = 0;
        end = 3;
    }
    int max_product=0;
    for(unsigned p=0; p<final_results.size(); p++){
        if(final_results[p]>max_product)
            max_product=final_results[p];
    }
    cout << max_product << endl;
}

void Project::highly_divisible_triangular_number(){
    int triangle=0;
    int n=1;
    while(Project::number_divisors(triangle)<500){
        triangle+=n;
        n++;
    }
    cout<< triangle << endl;
}
int Project::number_divisors(int number) {
    int numberDivisor = 0;
    int root = sqrt(number);

    for(int i = 1; i<= root; i++){
        if(number % i == 0){
            numberDivisor += 2;
        }
    }
    if (root * root == number) {
        numberDivisor--;
    }

    return numberDivisor;
}

void Project::large_sum(){
    int numbers[100][50];
    string line;
    int sum=0;
    int carry=0,remainder=0;
    vector<int>largenumber;

    ifstream myfile;
    myfile.open("digits.txt");
    int j=0;
    while(myfile.good())
    {
        getline(myfile,line);
        for(int i=0;i<50;i++)
            numbers[j][i]=charToInt(line[i]);
        j++;
    }
    myfile.close();

    int a=49;
    while(a>=0){
    sum=0;
    for(int b=0; b<100; b++){
        sum =sum + numbers[b][a];}
        sum=sum+carry;
        carry=sum/10;
        remainder=sum-carry*10;
        largenumber.insert(largenumber.begin(),remainder);
        a--;
        }
    largenumber.insert(largenumber.begin(),carry);

    for(int i=0;i<9;i++)
        cout<<largenumber[i];
    cout<<"\n";

}

int Project::charToInt(char line){
    if(line == '0')
        return 0;
    if (line == '1')
        return 1;
    if (line == '2')
        return 2;
    if (line == '3')
        return 3;
    if (line == '4')
        return 4;
    if (line == '5')
        return 5;
    if (line == '6')
        return 6;
    if (line == '7')
        return 7;
    if (line == '8')
        return 8;
    if (line == '9')
        return 9;

    return 0;
}


void Project::longest_collatz_sequence(){
    long int num_of_terms=0;
    long int highest_term=0;
    int num_with_highestTerm=0;

    for(int i=999999; i>1; i--){
        num_of_terms=collatz_func(i);
        if(num_of_terms>highest_term){
            highest_term=num_of_terms;
            num_with_highestTerm=i;}
    }
    cout << num_with_highestTerm << endl;
}

int Project::collatz_func(long long num){
    long int terms=1;
        while (num != 1)
        {
            if (num%2 == 0)
                num = num/2;
            else if (num%2 == 1)
                num = 3*num + 1;
            terms++;
        }
    return terms;
}

void Project::diophantine_reciprocals_a(){
    seive(MAX);
	for (int N = 1000; N < MAX; N++)
	{
		if (!composite[N])
			continue;
		int numdiv = 1, cn = N;
		for (unsigned i = 0; 1 != cn && i < primes.size(); i++)
		{
			int	count = 0;
			while (cn % primes[i] == 0)
			{
				cn /= primes[i];
				count++;
			}
			numdiv *= (count * 2 + 1);
		}
		int ans = (numdiv + 1) / 2;
		if (ans > LIMIT)
		{
			cout << N << endl;
			break;
		}
	}
}

void Project::seive(int n)
{
	int	i, j;

	for (i = 2; i * i <= n; i++)
	{
		if (composite[i])
			continue;
		for (j = 2 * i; j <= n; j += i)
			composite[j] = 1;
		primes.push_back(i);
	}
	for (; i <= n; i++)
		if (!composite[i])
			primes.push_back(i);
}

void Project::power_digit_sum(){
    stringstream ss;
    string num = "";
    int answer = 0;
    ss.setf(ios::fixed);
    ss << setprecision(0) << pow(2, 1000);
    ss >> num;
    for(unsigned int i = 0; i < num.length(); i++)
        answer += atoi(num.substr(i,1).c_str());
    cout << answer << endl;
}

void Project::number_letter_counts(){
    string dictionary1[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    string dictionary2[18] = { "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };
    string dictionary3[10] = { "onehundred", "twohundred", "threehundred", "fourhundred", "fivehundred", "sixhundred", "sevenhundred", "eighthundred", "ninehundred", "onethousand" };

    int sum_of_all_letters=0;
    int i=0,start,j,k;
    while(i<10){
        sum_of_all_letters+=dictionary1[i].length();
        i++;
        }
        sum_of_all_letters-=4;
    i=0;
    while(i<10){
        sum_of_all_letters+=dictionary2[i].length();
        i++;
    }
    start=10;
    while(start<18){
        sum_of_all_letters+=dictionary2[start].length();
        for(i=1; i<10; i++)
        sum_of_all_letters+=dictionary2[start].length()+dictionary1[i].length();
        start++;
    }
    j=0;
    start=10;
    while(j<9){
        sum_of_all_letters+=dictionary3[j].length();
        for(i=1; i<10; i++)
            sum_of_all_letters+=dictionary3[j].length()+dictionary1[i].length()+3;
        for(k=0; k<10; k++)
            sum_of_all_letters+=dictionary3[j].length()+dictionary2[k].length()+3;
        for(int p=10; p<18; p++)
            sum_of_all_letters+=dictionary3[j].length()+dictionary2[p].length()+3;
        while(start<18){
            for(int a=1; a<10; a++)
                sum_of_all_letters+=dictionary3[j].length()+dictionary2[start].length()+dictionary1[a].length()+3;
            start++;
        }
        start=10;
        j++;
    }
    sum_of_all_letters+=dictionary3[9].length();
    cout<<sum_of_all_letters<<endl;
}

void Project::maximum_path_sum_I(){
int tri [15][15] = {
    {75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {95, 64, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {17, 47, 82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {18, 35, 87, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {20, 4, 82, 47, 65, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {19, 1, 23, 75, 3, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {88, 2, 77, 73, 7, 63, 67, 0, 0, 0, 0, 0, 0, 0, 0},
    {99, 65, 4, 28, 6, 16, 70, 92, 0, 0, 0, 0, 0, 0, 0},
    {41, 41, 26, 56, 83, 40, 80, 70, 33, 0, 0, 0, 0, 0, 0},
    {41, 48, 72, 33, 47, 32, 37, 16, 94, 29, 0, 0, 0, 0, 0},
    {53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14, 0, 0, 0, 0},
    {70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57, 0, 0, 0},
    {91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48, 0, 0},
    {63, 66, 4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31, 0},
    {4, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 4, 23}};
    cout << path(15, tri) << endl;
}


int Project::maxsum (int num1, int num2, int up) {
    int biggest = num1;
    if(num2 > biggest)
        biggest = num2;
    return biggest + up;
}

int Project::path(int num, int tri[][15]) {
    for(int i = num-1; i >= 0; i--) {
        for(int j = 0; j+1 < num && tri[i][j+1] != 0; j++)
            tri[i-1][j] = maxsum(tri[i][j], tri[i][j+1], tri[i-1][j]);
    }
    return tri[0][0];
}

void Project::counting_sundays(){
    setStartDate(6, 1, 1901);
    cout << sundaysOnFirst(2000) << endl;
}

void Project::setStartDate(int startDay, int startMonth, int startYear) {
   day = startDay;
   month = startMonth;
   year = startYear;
}

bool Project::isLeapYear() {
    if(year % 100 == 0) {
        if(year % 400 == 0)
            return true;
        else
            return false;
    } else if(year % 4 == 0)
        return true;
    else
        return false;
}

int Project::daysInMonth() {
    if(month == 2) {
        if(isLeapYear())
            return 29;
        else
            return 28;
    } else if((month == 4) || (month == 6) || (month == 9) || (month == 11))
        return 30;
    else
        return 31;
}


void Project::updateDate(int numDays) {
    day += numDays;
    if(day > daysInMonth()) {
        day -= daysInMonth();
        month++;
    }
    if(month > 12) {
        month = 1;
        year++;
    }
}


int Project::sundaysOnFirst(int endYear) {
    int sundays = 0;
    for(; year <= endYear; updateDate(7)) {
        if(day == 1)
            sundays++;
    }
    return sundays;
}

void Project::factorial_digit_sum(){
string s = "93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000";
cout << sumDigits(s) << endl;
}

void Project::names_scores(){
ifstream myfile;
   string alpha="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
   string line, temp = "";
   int range=alpha.length();
   int rank=0;
   int range_x=0;
   int range_y=1;
   int letter=0;
   int prod=0;
   int i_n=0;
   unsigned long int sum = 0;
   myfile.open ("names.txt");
   getline(myfile,line);
   myfile.close();
   range_x = line.length();

   for(int i=0; i<range_x; i++ )
   {
       if(line.at(i)==',')
       {
            range_y++;
       }
   }
  string names[range_y];
    for(int i = 1; i < range_x; i++)
    {
        if(line.at(i) == '"' || line.at(i) == ',')
        {
            if(temp != "")
            {
                names[i_n] = temp;
                temp = "";
                i_n++;
            }
            continue;
        }
        temp += line.at(i);
    }

    for(int i = 0; i < range_y; i++)
    {
        for(int j = 0; j < range_y;j++)
        {
            if(names[i] > names[j])
            {
                string temp_r = names[j];
                names[j] = names[i];
                names[i] = temp_r;
            }
        }
    }


	 for(int i = 0; i < range_y; i++)
    {
        letter = 0;
        rank = range_y - i;
        int range_z = names[i].length();
        for(int m = 0; m < range_z; m++)
        {
            for(int n = 0; n < range; n++)
            {
                if(names[i].at(m) == alpha.at(n))
                {
                    letter += n + 1;
                    break;
                }
            }
        }

        prod=rank*letter;
        sum+=prod;
        }

    cout<< "Name Score Summation is:" << sum << endl;
}

int Project::sumDigits(string s) {
    int answer = 0;
    for(unsigned int i = 0; i < s.length(); i++)
        answer += atoi(s.substr(i,1).c_str());
    return answer;
}

