#include<iostream>
#include<vector>
#include<random>
#include<algorithm>
#include<ctime>

class expriment{
    private:
        int n , t , _wealth;
        std::vector<bool> has_money;
        std::vector<int> wealth;
        std::vector<int> other_arr;
    public:
        expriment(int n , int t , int _wealth):n(n) , t(t) , _wealth(_wealth){ 
            has_money = std::vector<bool>(n , false);
            wealth = std::vector<int>(n , _wealth);
            // other_arr = std::vector<int>(n-1 , 0);
        }

        void info(){
            std::cout << "The Gini coefficient of a society is a decimal between 0 and 1" << std::endl;
            std::cout << "A Gini coefficient of 0 represents complete equality in wealth" << std::endl;
            std::cout << "A Gini coefficient of 1 means one person holds all the wealth of the society" << std::endl;
            std::cout << "The smaller the Gini coefficient, the more balanced the distribution of wealth in society; the larger it is, the more unequal the distribution" << std::endl;
            std::cout << "In 2022, the average Gini coefficient across countries worldwide was 0.44" << std::endl;
            std::cout << "It is generally believed that when the Gini coefficient reaches 0.5" << std::endl;
            std::cout << "it signifies a very large gap between rich and poor, with a highly uneven distribution" << std::endl;
            std::cout << "The society might collapse into crisis as a result, such as experiencing a high crime rate or social unrest" << std::endl;
            std::cout << "Test begins" << std::endl;

            std::cout << "Number of people: " << n << std::endl << "Number of rounds: " << t << std::endl;



            evolution();
            sort(wealth.begin() , wealth.end());

            for(auto it : wealth){
                std::cout << it << " ";
            }

            double geni = calculate_geni();
            std::cout << std::endl << "geni: " << geni << std::endl;

            // for(auto it : other_arr){
            //     std::cout << it <<  " ";
            // }
        }

        void evolution(){
            
            int times = t;
            while(times--){
                for(int i = 0 ; i < n ; i++){
                    if(wealth[i] > 0)
                        has_money[i] = true;
                    else has_money[i] = false;
                }

                
                for(int i = 0 ; i < n ; i++){
                    int other = i;
                    if(has_money[i]){
                        do{
                            other = rand() % n ;
                        }while(other == i);

                        wealth[i] --;
                        wealth[other] ++;
                    }
                    // other_arr[other]++;
                }
            }
        }


        double calculate_geni(){
            int sum_of_wealth = n * _wealth;
            int sum_of_abs_diff = 0;

            for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < n ; j++){
                    sum_of_abs_diff += abs(wealth[i] - wealth[j]);
                }
            }

            return sum_of_abs_diff / (double) (2 * n * sum_of_wealth);
        }
};

int main()
{
    srand(time(nullptr));
    expriment exp(100 , 10000 , 10000);//n , t , _wealth
    exp.info();
}