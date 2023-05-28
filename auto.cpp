#include <iostream>
#include <windows.h>
#include <stdio.h>
/**
 * @author Sbleit
 * @see github.com/sbleitz
 * @version 2.0
 * @copyright autoclick creado por Sbleit usando C++.
*/
using namespace std;
void introDatosDelay(char slash){
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 10);
    cout<<"       __   __    __  .___  ___. .______    _______ .______         ____    ____      ___   "<<endl;
    Sleep(100);
    cout<<"      |  | |  |  |  | |   "<<slash<<"/   | |   _  "<<slash<<"  |   ____||   _  "<<slash<<"        "<<slash<<"   "<<slash<<"  /   /     |__ "<<slash<<" "<<endl;
    Sleep(100);
    cout<<"      |  | |  |  |  | |  "<<slash<<"  /  | |  |_)  | |  |__   |  |_)  |        "<<slash<<"   "<<slash<<"/   /         ) | "<<endl;
    Sleep(100);
    cout<<".--.  |  | |  |  |  | |  |"<<slash<<"/|  | |   ___/  |   __|  |      /          "<<slash<<"      /         / / "<<endl;
    Sleep(100);
    cout<<"|  `--'  | |  `--'  | |  |  |  | |  |      |  |____ |  |"<<slash<<"  "<<slash<<"----.      "<<slash<<"    /     __  / /_  "<<endl;
    Sleep(100);
    cout<<" "<<slash<<"______/   "<<slash<<"______/  |__|  |__| | _|      |_______|| _| `._____|       "<<slash<<"__/     (__)|____| "<<endl;
    Sleep(100);
    cout<<endl;
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 4);
    cout<<"\t\t\tBy Sbleit - https://github.com/SbleitZ"<<endl;
    
}
string estado("Desactivado");
POINT setpoint;
POINT cursorPos;
bool autoclick_active = false;
void introDatos(char slash, int posX, int posY){
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 10);
    cout<<"       __   __    __  .___  ___. .______    _______ .______         ____    ____      ___   "<<endl;
    cout<<"      |  | |  |  |  | |   "<<slash<<"/   | |   _  "<<slash<<"  |   ____||   _  "<<slash<<"        "<<slash<<"   "<<slash<<"  /   /     |__ "<<slash<<" "<<endl;
    cout<<"      |  | |  |  |  | |  "<<slash<<"  /  | |  |_)  | |  |__   |  |_)  |        "<<slash<<"   "<<slash<<"/   /         ) | "<<endl;
    cout<<".--.  |  | |  |  |  | |  |"<<slash<<"/|  | |   ___/  |   __|  |      /          "<<slash<<"      /         / / "<<endl;
    cout<<"|  `--'  | |  `--'  | |  |  |  | |  |      |  |____ |  |"<<slash<<"  "<<slash<<"----.      "<<slash<<"    /     __  / /_  "<<endl;
    cout<<" "<<slash<<"______/   "<<slash<<"______/  |__|  |__| | _|      |_______|| _| `._____|       "<<slash<<"__/     (__)|____| "<<endl;
    cout<<endl;
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 4);
    cout<<"\t\t\tBy Sbleit - https://github.com/SbleitZ"<<endl;
    // cout<<"Estado: "<<autoclick_active<<endl;
    cout<<"Setpoint: X:["<<posX<<"] Y:["<<posY<<"]"<<endl;
    printf("\033]0;Autoclick Jumper V.2 By Sbleit | Estado : %s \007", estado.c_str());
    // cout << "Setpoint fijado en: " << setpoint.x << ", " << setpoint.y << endl;
}


int main()
{
    char slash = 92;
    introDatosDelay(slash);
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
    // Fijamos el setpoint a la posición actual del mouse
    // GetCursorPos(&setpoint);
    int velocidad;
    cout<<"Elige la velocidad: ";
    cin>>velocidad;
    cout<<"La velocidad actual es: "<<velocidad<<endl;
    cout<<"Setpoint actual : X: "<<setpoint.x<<" Y: "<<setpoint.y<<endl;
    system("cls");
    introDatos(slash,setpoint.x,setpoint.y);
    while (true)
    {
        // Revisamos si se ha presionado alguna de las teclas F7, F8 o F9
        if (GetAsyncKeyState(VK_F7) & 0x8000)
        {
            // Si se ha presionado F7, fijamos el setpoint a la posición actual del mouse
            GetCursorPos(&setpoint);
            system("cls");
            introDatos(slash,setpoint.x,setpoint.y);
            // cout << "Setpoint fijado en: " << setpoint.x << ", " << setpoint.y << endl;
        }
        if (GetAsyncKeyState(VK_F8) & 0x8000)
        {
            printf("\033]0;Autoclick Jumper V.2 By Sbleit | Estado : Activado\007");
            // Si se ha presionado F8, activamos el autoclick
            autoclick_active = true;
            // cout << "Autoclick activado" << endl;
        }
        if (GetAsyncKeyState(VK_F9) & 0x8000)
        {
            printf("\033]0;Autoclick Jumper V.2 By Sbleit | Estado : Desactivado\007");
            // Si se ha presionado F9, desactivamos el autoclick
            autoclick_active = false;
            // cout << "Autoclick desactivado" << endl;
        }
        if (GetAsyncKeyState(VK_F10) & 0x8000)
        {
            fflush(stdin);
            cout<<"Elige nueva velocidad: ";
            cin>>velocidad;
            cout<<"La ahora es: "<<velocidad<<endl;
        }

        // Si el autoclick está activado, movemos el mouse al setpoint y hacemos clic
        if (autoclick_active)
        {
            // SetCursorPos(setpoint.x, setpoint.y);
            GetCursorPos(&cursorPos);
            SetCursorPos(setpoint.x, setpoint.y);
            mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
            SetCursorPos(cursorPos.x, cursorPos.y);
            Sleep(velocidad);
        }

        // Esperamos un poco antes de volver a revisar las teclas
    }

    return 0;
}
