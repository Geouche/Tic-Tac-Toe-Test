#include "raylib.h"

int main(void)
{
    const int screenWidth = 684;
    const int screenHeight = 685;

    InitWindow(screenWidth, screenHeight, "Tic-Tac-Toe");

    Image image = LoadImage("resources/tictactoe.png");     
    Texture2D texture = LoadTextureFromImage(image);          
    UnloadImage(image);   

    SetTargetFPS(60);     

    Rectangle playarea[] = { {0, 0, 221, 221}, {234, 0, 221, 221}, {464, 0, 221, 221},
                           {0, 234, 221, 221}, {234, 234, 221, 221}, {464, 234, 221, 221},
                           {0, 464, 221, 221}, {234, 464, 221, 221}, {464, 464, 221, 221}
    };
    int board[] = { {0}, {0}, {0},
                   {0}, {0}, {0},
                   {0}, {0}, {0} };
    


    Image player_x = LoadImage("resources/x.png");
    Texture2D PlayerX = LoadTextureFromImage(player_x);
    UnloadImage(player_x);

    Image line_h = LoadImage("resources/line_h.png");
    Texture2D LineH = LoadTextureFromImage(line_h);
    UnloadImage(line_h);

    Image line_v = LoadImage("resources/line_v.png");
    Texture2D LineV = LoadTextureFromImage(line_v);
    UnloadImage(line_v);

    Image line_bslsh = LoadImage("resources/line_bslash.png");
    Texture2D LineBS = LoadTextureFromImage(line_bslsh);
    UnloadImage(line_bslsh);

    Image line_fslsh = LoadImage("resources/line_fslash.png");
    Texture2D LineFS = LoadTextureFromImage(line_fslsh);
    UnloadImage(line_fslsh);

    Image player_o = LoadImage("resources/o.png");
    Texture2D PlayerO = LoadTextureFromImage(player_o);
    UnloadImage(player_o);

    
    while (!WindowShouldClose())    
    {
        Vector2 mouseposition = GetMousePosition();
       
        for (int n = 0; n <= 8; n++)
        {
            if (CheckCollisionPointRec(mouseposition, playarea[n]) && IsCursorOnScreen()) {
                DrawRectangleRec(playarea[n], LIGHTGRAY);
            }
            else { DrawRectangleRec(playarea[n], BLANK); }
        }
        for (int n = 0; n <= 8; n++)
        {
            if (CheckCollisionPointRec(mouseposition, playarea[n]) && IsCursorOnScreen() && IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && (board[n] == 0)) {
                board[n] = 1;
            }
            else if (CheckCollisionPointRec(mouseposition, playarea[n]) && IsCursorOnScreen() && IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && (board[n] == 1)) {
                board[n] = 0;
            }
            if (CheckCollisionPointRec(mouseposition, playarea[n]) && IsCursorOnScreen() && IsMouseButtonPressed(MOUSE_BUTTON_RIGHT) && (board[n] == 0)){
                board[n] = 2;
            }
            else if (CheckCollisionPointRec(mouseposition, playarea[n]) && IsCursorOnScreen() && IsMouseButtonPressed(MOUSE_BUTTON_RIGHT) && (board[n] == 2)) {
                board[n] = 0;
            }
        }
        for (int n = 0; n <= 8; n++) {
            if ((board[n] == 1)) {
                DrawTexture(PlayerX, playarea[n].x, playarea[n].y, RAYWHITE);
            }
            if ((board[n] == 2)) {
                DrawTexture(PlayerO, playarea[n].x, playarea[n].y, RAYWHITE);
            }
        }

        if ((board[0] == 1) && (board[1] == 1) && (board[2] == 1)) {
            DrawTexture(LineH, playarea[0].x, playarea[0].y + 92, RAYWHITE);
        }
        else if ((board[0] == 2) && (board[1] == 2) && (board[2] == 2)) {
            DrawTexture(LineH, playarea[0].x, playarea[0].y + 92, RAYWHITE);
        }

        if ((board[3] == 1) && (board[4] == 1) && (board[5] == 1)) {
            DrawTexture(LineH, playarea[3].x, playarea[3].y + 92, RAYWHITE);
        }
        else if ((board[3] == 2) && (board[4] == 2) && (board[5] == 2)) {
            DrawTexture(LineH, playarea[3].x, playarea[3].y + 92, RAYWHITE);
        }

        if ((board[6] == 1) && (board[7] == 1) && (board[8] == 1)) {
            DrawTexture(LineH, playarea[6].x, playarea[6].y + 92, RAYWHITE);
        }
        else if ((board[6] == 2) && (board[7] == 2) && (board[8] == 2)) {
            DrawTexture(LineH, playarea[6].x, playarea[6].y + 92, RAYWHITE);
        }

        if ((board[0] == 1) && (board[3] == 1) && (board[6] == 1)) {
            DrawTexture(LineV, playarea[0].x + 92, playarea[0].y, RAYWHITE);
        }
        else if ((board[0] == 2) && (board[3] == 2) && (board[6] == 2)) {
            DrawTexture(LineV, playarea[0].x + 92, playarea[0].y, RAYWHITE);
        }

        if ((board[1] == 1) && (board[4] == 1) && (board[7] == 1)) {
            DrawTexture(LineV, playarea[1].x + 92, playarea[1].y, RAYWHITE);
        }
        else if ((board[1] == 2) && (board[4] == 2) && (board[7] == 2)) {
            DrawTexture(LineV, playarea[1].x + 92, playarea[1].y, RAYWHITE);
        }

        if ((board[2] == 1) && (board[5] == 1) && (board[8] == 1)) {
            DrawTexture(LineV, playarea[2].x + 92, playarea[2].y, RAYWHITE);
        }
        else if ((board[2] == 2) && (board[5] == 2) && (board[8] == 2)) {
            DrawTexture(LineV, playarea[2].x + 92, playarea[2].y, RAYWHITE);
        }

        if ((board[0] == 1) && (board[4] == 1) && (board[8] == 1)) {
            DrawTexture(LineBS, playarea[0].x, playarea[0].y, WHITE);
        }
        else if ((board[0] == 2) && (board[4] == 2) && (board[8] == 2)) {
            DrawTexture(LineBS, playarea[0].x, playarea[0].y, WHITE);
        }

        if ((board[2] == 1) && (board[4] == 1) && (board[6] == 1)) {
            DrawTexture(LineFS, playarea[0].x, playarea[0].y, WHITE);
        }
        else if ((board[2] == 2) && (board[4] == 2) && (board[6] == 2)) {
            DrawTexture(LineFS, playarea[0].x, playarea[0].y, WHITE);
        }

        
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(texture, screenWidth / 2 - texture.width / 2, screenHeight / 2 - texture.height / 2, WHITE);



        EndDrawing();
        
    }

   
    UnloadTexture(texture);       

    CloseWindow();                
    

    return 0;
}
