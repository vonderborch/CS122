#include "lab9.h"
 
//  Some Constants for the Pond simulation
 
const size_t   MANY_WEEDS        = 1000;  // number of weeds in the pond
const double   WEED_SIZE         = 10;    // initial size of each weed, in ounces
const double   WEED_RATE         = 1;   // growth rate of the weeds
const size_t   INIT_FISH         = 300;   // the initial number of fish in the pond
const double   FISH_SIZE         = 50;    // initial fish size in ounces
const double   FRACTION          = 0.5;   // a fish eats FRACTION of its size each
                                          // week to not die
 
const int      AVERAGE_NIBBLES   = 30;    // average number of plants nibbled on by a fish
                                          // each week
 
const double   BIRTH_RATE        = 0.05;  // at the end of each week, some fish eggs
                                          // hatch to new baby gold fish. yea! The
                                          // total number of new fish born is the
                                          // current number of fish times BIRTH_RATE
 
void pondWeek( vector<GoldFish>&  fishes, vector<Plant>&  mosses);
double total_mass(const vector<Plant>&  stuff);
 
// examples to start the simulation with
const Plant SAMPLE_WEED(WEED_SIZE, WEED_RATE);
const GoldFish SAMPLE_FISH(FISH_SIZE, 0, FISH_SIZE * FRACTION);
 
 void main (void)
{
   vector<Plant> moss(MANY_WEEDS, SAMPLE_WEED);    // a vector of moss
   vector<GoldFish> fish(INIT_FISH, SAMPLE_FISH);  // a vector of fish
 
   int numberWeeks = 1000;
   int i = 0;

   srand( (unsigned)time( NULL ) );
 
   cout << "Week      Number      Moss Mass" << endl;
 
   for (int i = 1; i <= numberWeeks; i++)
   {
      pondWeek(fish, moss);
      cout << setw(4) << i;
      cout << setw(10) << fish.size ();
      cout << setw(14) << setprecision(0) << total_mass(moss);
      cout << endl;
   }
}
 
double total_mass(const vector<Plant>& weed)
{
   double answer = 0.0;
 
   for (int i = 0; (unsigned)i < weed.size(); i++)
   {
      answer += weed[i].get_size ();
   }
   return answer;
}
 
void pondWeek(vector<GoldFish>& fish, vector<Plant>& moss)
{
   vector<Plant>::iterator       wi;
   vector<Plant>::size_type      weed_index;
 
   vector<GoldFish>::iterator    fi;
   vector<GoldFish>::size_type   fish_index;
   vector<GoldFish>::size_type   new_fish_population;
 
   int many_iteration = AVERAGE_NIBBLES * fish.size();
 
   // fish swim around and chomp on plants. sort of a random process.
   for (int i = 0; i < many_iteration; i++)
   {
      fish_index  = rand() % fish.size();
      weed_index  = rand() % moss.size();
      fish[fish_index].nibble(moss[weed_index]);
   }
 
   // so what happens to the plants
   for (wi = moss.begin(); wi != moss.end(); wi++)
   {
      wi->simulate_week ();
   }
 
   // and what happens to the fishies
 
   fi = fish.begin();   // this is a vector iterator CS 223 :)
   while (fi != fish.end())
   {
      fi->simulate_week();
      if(!fi->is_alive())
      {
		 fi = fish.erase (fi);
      }
      else
      {
         fi++;
      }
   }
 
   new_fish_population = (unsigned)((1 + BIRTH_RATE) * fish.size());
   fish.resize(new_fish_population, SAMPLE_FISH);
}