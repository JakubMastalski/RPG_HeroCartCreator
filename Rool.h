#pragma once
#include <cstdlib>
#include <ctime>
#include <string>
#include <thread>
#include <chrono>
#include <iostream>



namespace RPG_HERO_CREATOR {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;


	/// <summary>
	/// Summary for Rool
	/// </summary>
	public ref class Rool : public System::Windows::Forms::Form
	{
	public:
		Rool(void);
	protected:
		~Rool();
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ d2_dice;
	private: System::Windows::Forms::Button^ d6_dice;
	private: System::Windows::Forms::Button^ d4_dice;
	private: System::Windows::Forms::Button^ d100_dice;
	private: System::Windows::Forms::Button^ d20_dice;
	private: System::Windows::Forms::Button^ d12_dice;
	private: System::Windows::Forms::Button^ d10_dice;
	private: System::Windows::Forms::Button^ d8_dice;
	private: System::Windows::Forms::Label^ label_dice;
	private: System::Windows::Forms::ComboBox^ rool_number;
	private: System::Windows::Forms::PictureBox^ dice_pb;
	private: System::Windows::Forms::Timer^ dice_timer;
	private: System::Windows::Forms::Label^ rool_result;


	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void);
#pragma endregion
		private:
		//number of dices choosen by player
		int player_choice;
		//INITAL RANDOM NUMBER GENERATOR
		Random^ random_number = gcnew Random();
		Random^ random_font = gcnew Random();
		//DICE THROW RESULT GLOBAL VARIABLE 
		int dice_result_variable = 0;
		int dice_result_variable2 = 0;
		//CHANGE FONT COLOR
		int font_color = 0;

private: void new_color();
		//SOUND THROWING A DICE
		 System::Media::SoundPlayer^ player_rool = gcnew System::Media::SoundPlayer("C:\\Users\\USER\\Desktop\\Warhamer_UI\\snd\\dice.wav");
		//D2 DICE HEAD OR TAIL
private: System::Void d2_dice_Click(System::Object^ sender, System::EventArgs^ e);
		//D4 DICE 1..4 NUMBERS
private: System::Void d4_dice_Click(System::Object^ sender, System::EventArgs^ e);
	   //CLEAR TEXT
private: System::Void Rool_Load(System::Object^ sender, System::EventArgs^ e);
	   //D6 DICE 1..6 NUMBERS
private: System::Void d6_dice_Click(System::Object^ sender, System::EventArgs^ e);
	   //D8 DICE 1..8 NUMBERS
private: System::Void d8_dice_Click(System::Object^ sender, System::EventArgs^ e);
	   //D10 DICE 1..10 NUMBERS
private: System::Void d10_dice_Click(System::Object^ sender, System::EventArgs^ e);
	   //D12 DICE 1..12 NUMBERS  
private: System::Void d12_dice_Click(System::Object^ sender, System::EventArgs^ e);
	   //D20 DICE 1..20 NUMBERS 
private: System::Void d20_dice_Click(System::Object^ sender, System::EventArgs^ e);
	   //D100 DICE 1..100 NUMBERS 
private: System::Void d100_dice_Click(System::Object^ sender, System::EventArgs^ e);
private:
	//draging form
	   bool draging;
	   Point offset;
	   //enable draging get mouse position
private: System::Void Rool_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	//check wheter able to move
private: System::Void Rool_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	//disable draging
private: System::Void Rool_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	 //set dice number
private: System::Void rool_number_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
	//set dice number
	//draging
	   bool draging2;
	   Point offset2;
private: System::Void rool_result_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
private: System::Void rool_result_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	//get current pos
	//disable draging
private: System::Void rool_result_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	   //disable draging
private: void wait_thread();
	//timer 
private: System::Void dice_timer_Tick(System::Object^ sender, System::EventArgs^ e);
	//button font change
private:void font_change();
};
}
