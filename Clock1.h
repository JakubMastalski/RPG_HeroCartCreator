#pragma once

namespace RPG_HERO_CREATOR {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class Clock : public System::Windows::Forms::Form
    {
    private:
    private:
        //variables to track time
        int seconds = 0;
        int minutes = 0;
        int hours = 0;
        int ms = 0;
        //variables to drag form
        String^ time = "00:00:00";
        bool draging = false;
        Point offset;
    public:
        //construktor
        Clock(void);
    protected:
        //destruktor
        ~Clock();
    private:
        //visual objects
        System::Windows::Forms::Panel^ panel_clock_image;
        System::Windows::Forms::PictureBox^ clock_image;
        System::Windows::Forms::Button^ reset_b;
        System::Windows::Forms::Button^ start_stop_b;
        System::Windows::Forms::Panel^ panel2;
        System::Windows::Forms::Label^ time_label;
        System::Windows::Forms::Timer^ timer_clock;
        System::ComponentModel::Container^ components;

        void InitializeComponent();
        //reset timer
        System::Void reset_b_Click(System::Object^ sender, System::EventArgs^ e);
        //start or stop timer
        System::Void start_stop_b_Click(System::Object^ sender, System::EventArgs^ e);
        //timer 
        System::Void timer_clock_Tick(System::Object^ sender, System::EventArgs^ e);
        //measures the passing time every second
        System::Void Clock_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
        //enenable dragging form
        System::Void Clock_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
        //geting current mouse pos 
        System::Void Clock_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
        //disable dragging form

    };
}