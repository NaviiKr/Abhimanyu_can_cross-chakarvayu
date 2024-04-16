#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> PBDS;
 
/*-------------------------------------------------------------------------------------------*/
bool cross(vector<int> & enemy_power,int power,int boon,priority_queue<int> q){
    for(int i =0;i<11;i++){
      if(i == 2 || i  == 6){
        /*check if power is less than enemy i  we have to skip 
          2 circle because in case of 3 and 7 circle it can attack from behind
        */
        if(power < enemy_power[i] && boon >= 2){
            if(q.top() == enemy_power[i]){
                q.pop();
            }
            if(q.top() == enemy_power[i+1]){
                q.pop();
            }
            boon -= 2;
            i++;
        }else if(power < enemy_power[i]){
            return false;
        }else{
            power -= enemy_power[i];
        }
      }else{
        // if enemy i is most power remaining and we have boon so we can skip it
         if(enemy_power[i] == q.top() && boon > 0){
              q.pop();
              boon -= 1;
         }else{
            // else if power of abhimanyu is less than enemy i and no boon left so there is no option abhimanyu have to get out from circle 
            if(power < enemy_power[i]){
                if(boon > 0){
                    boon -= 1;
                }else{
                    return false;
                }
            //abhimanyu win the fight with he loss power - enemy_power[i]
            }else{
                power -= enemy_power[i];
            }
         } 
      }
    }
    cout<<power<<endl;
    return true;
}

void solve(){
 vector<int> enemy_power(11);
 for(int i = 0;i<11;i++){
    cin>>enemy_power[i];
 }
 int power,boon,recharge;
 cin>>power;
 cin>>boon;
 cin>>recharge;
 // total power of enenmy 3 and 7 is enemy = enemy + 0.5*enemy
 enemy_power[2]  += (enemy_power[2]/2);
 enemy_power[6]  += (enemy_power[6]/2);
 // we can refill the power recharger time so total power id power = power*(recharge+1)
 power += (power*recharge);
 priority_queue<int> q;
 for(int i =0;i<11;i++){
    q.push(enemy_power[i]);
 }
 if(cross(enemy_power,power,boon,q)){
    cout<<"YES"<<endl;
 }else{
    cout<<"NO"<<endl;
 }
}
 
signed main(){
  ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   cout<<fixed;
   cout<<setprecision(10);
   int t;
   cin>>t;
   while(t--){
    solve();
   }
 return 0;
}
