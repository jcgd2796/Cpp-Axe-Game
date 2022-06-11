/**
 * Axe dodge minigame created using C++ and RayLib library"
 * Created by "jcgd2796" following GaveDev C++ Fundamentals: Game Programming For Beginners guide
**/
#include "raylib.h"
int main(){
    //canvas size
    int width = 800;
    int height = 600;

    //circle location and size
    int circle_center_x = width*0.25;
    int circle_center_y = height*0.5;
    int circle_radius = 10;

    //axe1 location, size and movement
    int axe1_start_x = width*0.5;
    int axe1_start_y = 0;
    int axe1_width = 50;
    int axe1_height = 50;
    int axe1_x_movement = 10;

    //axe2 location, size and movement
    int axe2_start_x = width*0.65;
    int axe2_start_y = height*0.5;
    int axe2_width = 25;
    int axe2_height = 25;
    int axe2_x_movement = 20;

    //axe3 location, size and movement
    int axe3_start_x = width*0.85;
    int axe3_start_y = height*0.75;
    int axe3_width = 15;
    int axe3_height = 15;
    int axe3_x_movement = 30;

    //left, right, upper and bottom boundaries for the circles and axes
    int l_circle_x,r_circle_x,u_circle_y,b_circle_y,
    l_axe1_x,r_axe1_x,u_axe1_y,b_axe1_y,
    l_axe2_x,r_axe2_x,u_axe2_y,b_axe2_y,
    l_axe3_x,r_axe3_x,u_axe3_y,b_axe3_y;

    //finish left and upper rectangle boundaries
    int l_finish_x = width*0.9,u_finish_y = 0;
    
    bool start = false, collision = false, victory = false;

    InitWindow(width,height,"Axe game");
    SetTargetFPS(60);
    while(!WindowShouldClose()){
        //main window
        while(!WindowShouldClose() && !start){
            if(IsKeyDown(KEY_ENTER) || WindowShouldClose()){start = true;}
            BeginDrawing();
            ClearBackground(WHITE);
            DrawText("Axe game",width*0.1,height*0.1,100,BLACK);
            DrawText("Controls\n Use \"W\", \"A\", \"S\" \"D\" to move the circle\n Avoid the squares and reach the right side of the window to win",width*0.1,height*0.25,20,BLACK);
            DrawText("Press enter to start",width*0.1,height*0.50,50,BLACK);
            EndDrawing();
        }

        //update the boundaries
        l_circle_x = circle_center_x-circle_radius;
        r_circle_x = circle_center_x+circle_radius;
        u_circle_y = circle_center_y-circle_radius;
        b_circle_y = circle_center_y+circle_radius;

        l_axe1_x = axe1_start_x;
        r_axe1_x = axe1_start_x+axe1_width;
        u_axe1_y = axe1_start_y;
        b_axe1_y = axe1_start_y + axe1_height;

        l_axe2_x = axe2_start_x;
        r_axe2_x = axe2_start_x+axe2_width;
        u_axe2_y = axe2_start_y;
        b_axe2_y = axe2_start_y + axe2_height;

        l_axe3_x = axe3_start_x;
        r_axe3_x = axe1_start_x+axe3_width;
        u_axe3_y = axe1_start_y;
        b_axe3_y = axe1_start_y + axe3_height;

        
        BeginDrawing();
        if(collision){
            ClearBackground(WHITE);
            DrawText("Game Over",width*0.5,height*0.5,50,RED);
        }else if(victory){
            ClearBackground(WHITE);
            DrawText("Victory!",width*0.5,height*0.5,50,GREEN); 
        }
        else{
            //check if collision occured
            if ((r_circle_x >= l_axe1_x && r_circle_x <= r_axe1_x && u_circle_y <= b_axe1_y && u_circle_y >= u_axe1_y)
             || (l_circle_x <= r_axe1_x && l_circle_x >= l_axe1_x && b_circle_y <= b_axe1_y && u_circle_y >= b_axe1_y)
             || (r_circle_x >= l_axe1_x && r_circle_x <= r_axe1_x && b_circle_y >= u_axe1_y && b_circle_y <= b_axe1_y)
             || (l_circle_x <= r_axe1_x && l_circle_x >= l_axe1_x && b_circle_y >= u_axe1_y && b_circle_y <= b_axe1_y) 
             || (r_circle_x >= l_axe2_x && r_circle_x <= r_axe2_x && u_circle_y <= b_axe2_y && u_circle_y >= u_axe2_y)
             || (l_circle_x <= r_axe2_x && l_circle_x >= l_axe2_x && b_circle_y <= b_axe2_y && u_circle_y >= b_axe2_y) 
             || (r_circle_x >= l_axe2_x && r_circle_x <= r_axe2_x && b_circle_y >= u_axe2_y && b_circle_y <= b_axe2_y)
             || (l_circle_x <= r_axe2_x && l_circle_x >= l_axe2_x && b_circle_y >= u_axe2_y && b_circle_y <= b_axe2_y)
             || (r_circle_x >= l_axe3_x && r_circle_x <= r_axe3_x && u_circle_y <= b_axe3_y && u_circle_y >= u_axe3_y)
             || (l_circle_x <= r_axe3_x && l_circle_x >= l_axe3_x && b_circle_y <= b_axe3_y && u_circle_y >= b_axe3_y) 
             || (r_circle_x >= l_axe3_x && r_circle_x <= r_axe3_x && b_circle_y >= u_axe3_y && b_circle_y <= b_axe3_y)
             || (l_circle_x <= r_axe3_x && l_circle_x >= l_axe3_x && b_circle_y >= u_axe3_y && b_circle_y <= b_axe3_y)
             ){
                collision = true;
                }
            //check if victory occured
            if (r_circle_x >= l_finish_x){
                victory = true;
                }

            ClearBackground(WHITE);
            //Draw the elements and move the axes
            DrawCircle(circle_center_x,circle_center_y,circle_radius,BLUE);
            DrawRectangle(axe1_start_x,axe1_start_y,axe1_width,axe1_height,RED);
            DrawRectangle(axe2_start_x,axe2_start_y,axe2_width,axe2_height,RED);
            DrawRectangle(axe3_start_x,axe3_start_y,axe3_width,axe3_height,RED);
            DrawRectangle(l_finish_x,u_finish_y,width*0.1,height,GREEN);
            axe1_start_y += axe1_x_movement;
            axe2_start_y += axe2_x_movement;
            axe3_start_y += axe3_x_movement;
            //invert axe movement if reached limit of the canvas
            if (axe1_start_y > height-axe1_height || axe1_start_y < 0){
                axe1_x_movement *=-1;
            }
            if (axe2_start_y > height-axe2_height || axe2_start_y < 0){
                axe2_x_movement *=-1;
            }
            if (axe3_start_y > height-axe3_height || axe3_start_y < 0){
                axe3_x_movement *=-1;
            }

            //Circle movement
            if (IsKeyDown(KEY_D) && circle_center_x + circle_radius < width ){
                    circle_center_x += 10;
                    ClearBackground(WHITE);
                    DrawCircle((circle_center_x),circle_center_y,circle_radius,BLUE);
            }
            if (IsKeyDown(KEY_A) && circle_center_x - circle_radius > 0){
                    circle_center_x -= 10;
                    ClearBackground(WHITE);
                    DrawCircle((circle_center_x),circle_center_y,circle_radius,BLUE);
            }
            if (IsKeyDown(KEY_W) && circle_center_y - circle_radius > 0){
                circle_center_y -= 10;
                    ClearBackground(WHITE);
                    DrawCircle((circle_center_x),circle_center_y,circle_radius,BLUE);
            }
                if (IsKeyDown(KEY_S)&& circle_center_y + circle_radius < height){
                circle_center_y += 10;
                    ClearBackground(WHITE);
                    DrawCircle((circle_center_x),circle_center_y,circle_radius,BLUE);
            }  
        }
        EndDrawing();
    }
    
}