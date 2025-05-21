using System;
using System.Globalization;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

namespace pratice
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] n=Array.ConvertAll(Console.ReadLine().Split(" "),int.Parse);
            List<int> coin=new List<int>();
            for(int i=0;i<n[0];i++){
                coin.Add(int.Parse(Console.ReadLine()));
            }
            coin.Sort();
            int cnt=0;
            int c=0;
            for(int i=n[0]-1;i>=0;i--){
                if(coin[i]<=n[1]){
                    while(c<n[1]){
                        c+=coin[i];
                        cnt++;
                    }
                    if(c>n[1]){
                        cnt--;
                        c-=coin[i];
                    }
                }
            }
            Console.Write(cnt);
        }
    }
}