#pragma once
#include "Windows.h"
#include "exception"
#include "CreateHero.h"
#include "Clock1.h"
#include "Rool.h"

namespace RPG_HERO_CREATOR {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void);
	protected:
		~MyForm();
	private: System::Windows::Forms::PictureBox^ menu_picture1;
	private: System::Windows::Forms::Label^ main_label1;
	private: System::Windows::Forms::Button^ main_button_options;
	private: System::Windows::Forms::Panel^ main_panel1;
	private: System::Windows::Forms::Button^ main_exit_b;
	private: System::Windows::Forms::Button^ main_role_b;
	private: System::Windows::Forms::Button^ main_create_b;
	private: System::Windows::Forms::Button^ sound_b;
	private: System::Windows::Forms::Timer^ menu_timer;
	private: System::Windows::Forms::Timer^ close_menu_timer;
	private: System::Windows::Forms::Button^ create_hero_b;
	private: System::Windows::Forms::Button^ main_clock_b;
    //Managing Forms
	private: Rool^ rool_form = gcnew Rool();
	private: CreateHero^ hero_form = gcnew CreateHero();
	private:Clock^ new_clock = gcnew Clock();
	//variables
	bool panel_expanted; //boolen flag
	bool dragging;//dragging form
	Point offset;//dragging form
    const int interval = 20; //interval  value
	//music
	System::Media::SoundPlayer^ player;
	bool isPlaying;

    //system win forms components
	private: System::ComponentModel::IContainer^ components;

#pragma region Windows Form Designer generated code

		 //initializer
		   void MyForm::InitializeComponent(void);
#pragma endregion

		//show/close menu//enable menu_timer
	private: System::Void main_button_options_Click(System::Object^ sender, System::EventArgs^ e);

		 //close application
	private: System::Void main_exit_b_Click(System::Object^ sender, System::EventArgs^ e);
		
       //enebale dragging set Point variable
	private: System::Void menu_picture1_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
		//if draging enablecheck current mouse pos and get loccation

	private: System::Void menu_picture1_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);

		   //disable draging
	private: System::Void menu_picture1_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);

		   //play music
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e);

		   //mute sound//play
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);

		   //open role dick form
	private: System::Void main_role_b_Click(System::Object^ sender, System::EventArgs^ e);

	   //animation show menu//button START line 431
	private: System::Void menu_timer_Tick(System::Object^ sender, System::EventArgs^ e);

		   //closeing and opening menu
	private: System::Void close_menu_timer_Tick(System::Object^ sender, System::EventArgs^ e);

	   //create hero form
	private: System::Void create_hero_b_Click(System::Object^ sender, System::EventArgs^ e);
		   //create timer form obj
	private: System::Void main_clock_b_Click(System::Object^ sender, System::EventArgs^ e);
};
}

