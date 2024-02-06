#include<SDL2/SDL.h>
#include <cstdio>
#include<iostream>
#include<random>
#include<ranges>
#include<algorithm>
#include <utility>
#include <vector>

using namespace std;

std::random_device rd;
std::uniform_int_distribution d(1,99);
std::vector<int> v;

void draw_state(
    vector<int>&v, 
    SDL_Renderer* renderer, 
    unsigned int red, 
    unsigned int blue ){
    int index = 0;

    for (int i : v){
        if(index == red){
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        } else if(index == blue){
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        } 
        else 
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderDrawLine(renderer, index, 99, index, i);
        index += 1;
    }
        //SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

}

int main(){
    for (int i=0; i <100; i++) {
        v.push_back(d(rd));
    }

    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;

    SDL_CreateWindowAndRenderer(
        100 * 10, 100 * 10, 0,
        &window, &renderer);
    
    SDL_RenderSetScale(renderer, 10, 10);


    for(unsigned int i=0; i< v.size(); i++){
        for(unsigned int j=0; j< v.size(); j++){
            if(v[i] > v[j]){
                swap(v[i], v[j]);
            }
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

            SDL_RenderClear(renderer);
            draw_state(v, renderer, i, j);

            SDL_RenderPresent(renderer);
            SDL_Delay(4);
        }
    }

    for (int i : v) {
        cout << i << " ";
    }
    printf("\n");

    if(std::ranges::is_sorted(v)){
        cout << "\nsorted\n";
    }
}