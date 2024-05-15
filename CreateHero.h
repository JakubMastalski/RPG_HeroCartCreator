#pragma once
#include "exception" //errors show user
#include <fstream>   //files
#include <Windows.h> //time
#include "string"    //strings
#include "vector"    //list to random 
#include <algorithm> //add
#include <vcclr.h>   //list to random
#include <ctime>    //start randomize
#include <cstdlib>  //random

namespace RPG_HERO_CREATOR {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	

	/// <summary>
	/// Summary for CreateHero
	/// </summary>
	public ref class CreateHero : public System::Windows::Forms::Form
	{
	public:
	
		CreateHero(void);
	protected:
		~CreateHero();
		//create object to use random
	public:
		Random^ random_number;
		Random^ random_comparenumber;
		List<String^>^ men_names;
		List<String^>^ women_names;
		List<String^>^ hero_races;
		List<String^>^ hero_profession;
		List<String^>^ hero_star_sign;
		List<String^>^ hero_placeofbirth;
		String^ hero_strings;
		bool sex;
		//variables to check whether test is passed and add points to hero stats
		int WW, US, K, ODP, ZR, INT, SW, OGD;
		//secondary variables to add points to hero stats
		int A, ZYW, S, WT, SZ, MAG, PO, PP;
		//to random
		int race_index;
		int random_age;
		String^ age_str;
		int random_height;
		String^ height_str;
		int random_weight;
		String^ weight_str;
		int siblings;
		String^ siblings_str;
		int features;
		int comparenumber;




private: System::Windows::Forms::Panel^ panel_hero1;
private: System::Windows::Forms::Panel^ panel2;
private: System::Windows::Forms::Label^ hero_label;
private: System::Windows::Forms::Label^ label_cur_profesion;
private: System::Windows::Forms::Label^ label_race;
private: System::Windows::Forms::Label^ label_name;
private: System::Windows::Forms::TextBox^ textbox_prev_prof;
private: System::Windows::Forms::TextBox^ textbox_cur_prof;
private: System::Windows::Forms::TextBox^ textbox_race;
private: System::Windows::Forms::TextBox^ textbox_name;
private: System::Windows::Forms::Label^ label_prev_profession;
private: System::Windows::Forms::Panel^ panel_images;
private: System::Windows::Forms::Panel^ panel_hero_img;
private: System::Windows::Forms::TextBox^ tb_leftfootarrmor;
private: System::Windows::Forms::TextBox^ tb_rightfarmor;
private: System::Windows::Forms::TextBox^ tb_lefthandarmor;
private: System::Windows::Forms::TextBox^ tb_rhandarmor;
private: System::Windows::Forms::TextBox^ tb_bodyarmor;
private: System::Windows::Forms::TextBox^ tb_headarmor;
private: System::Windows::Forms::Label^ label7;
private: System::Windows::Forms::Label^ label6;
private: System::Windows::Forms::Label^ label5;
private: System::Windows::Forms::Label^ label4;
private: System::Windows::Forms::Label^ label3;
private: System::Windows::Forms::Label^ label2;
private: System::Windows::Forms::Label^ label_armor_points;
private: System::Windows::Forms::Panel^ panel_herodesc;
private: System::Windows::Forms::TextBox^ textbox_birthplace;
private: System::Windows::Forms::TextBox^ textbox_siblings;
private: System::Windows::Forms::TextBox^ textbox_weight;
private: System::Windows::Forms::TextBox^ textbox_height;
private: System::Windows::Forms::TextBox^ textbox_star_sign;
private: System::Windows::Forms::TextBox^ textbox_sex;
private: System::Windows::Forms::Label^ label8;
private: System::Windows::Forms::Label^ label9;
private: System::Windows::Forms::Label^ label10;
private: System::Windows::Forms::Label^ label11;
private: System::Windows::Forms::Label^ label12;
private: System::Windows::Forms::TextBox^ textbox_age;
private: System::Windows::Forms::Panel^ panel_hero_description;
private: System::Windows::Forms::Label^ label_hero_description;
private: System::Windows::Forms::Panel^ panel7;
private: System::Windows::Forms::Label^ label14;
private: System::Windows::Forms::Label^ label15;
private: System::Windows::Forms::Panel^ panel_feat;
private: System::Windows::Forms::Label^ label_development1;
private: System::Windows::Forms::Label^ label_initial1;
private: System::Windows::Forms::Label^ label_featuresmain;
private: System::Windows::Forms::Panel^ panel_features;
private: System::Windows::Forms::Label^ features_label;
private: System::Windows::Forms::Label^ label_WW;
private: System::Windows::Forms::Label^ label_current2;
private: System::Windows::Forms::Label^ label_initial2;
private: System::Windows::Forms::Label^ label_secondary;
private: System::Windows::Forms::Label^ label_current1;
private: System::Windows::Forms::Label^ label32;
private: System::Windows::Forms::Label^ label_K;
private: System::Windows::Forms::Label^ label_SW;
private: System::Windows::Forms::Label^ label_INT;
private: System::Windows::Forms::Label^ label_ZR;
private: System::Windows::Forms::Label^ label_OGD;
private: System::Windows::Forms::Label^ label_US;
private: System::Windows::Forms::Label^ label_PP;
private: System::Windows::Forms::Label^ label_PO;
private: System::Windows::Forms::Label^ label_MAG;
private: System::Windows::Forms::Label^ label_SZ;
private: System::Windows::Forms::Label^ label_WT;
private: System::Windows::Forms::Label^ label_S;
private: System::Windows::Forms::Label^ label_ZYW;
private: System::Windows::Forms::Label^ label_A;
private: System::Windows::Forms::TextBox^ textbox_WWc;
private: System::Windows::Forms::TextBox^ textbox_WWa;
private: System::Windows::Forms::TextBox^ textbox_PPc;
private: System::Windows::Forms::TextBox^ textbox_POc;
private: System::Windows::Forms::TextBox^ textbox_PPa;
private: System::Windows::Forms::TextBox^ textbox_POa;
private: System::Windows::Forms::TextBox^ textbox_MAGc;
private: System::Windows::Forms::TextBox^ textbox_MAGa;
private: System::Windows::Forms::TextBox^ textbox_SZc;
private: System::Windows::Forms::TextBox^ textbox_SZa;
private: System::Windows::Forms::TextBox^ textbox_WTc;
private: System::Windows::Forms::TextBox^ textbox_WTa;
private: System::Windows::Forms::TextBox^ textbox_Sc;
private: System::Windows::Forms::TextBox^ textbox_Sa;
private: System::Windows::Forms::TextBox^ textbox_ZYWc;
private: System::Windows::Forms::TextBox^ textbox_Aa;
private: System::Windows::Forms::TextBox^ textbox_OGDc;
private: System::Windows::Forms::TextBox^ textbox_OGDa;
private: System::Windows::Forms::TextBox^ textbox_SWc;
private: System::Windows::Forms::TextBox^ textbox_SWa;
private: System::Windows::Forms::TextBox^ textbox_Ac;
private: System::Windows::Forms::TextBox^ textbox_INTc;
private: System::Windows::Forms::TextBox^ textbox_INTa;
private: System::Windows::Forms::TextBox^ textbox_ZYWa;
private: System::Windows::Forms::TextBox^ textbox_ZRc;
private: System::Windows::Forms::TextBox^ textbox_ZRa;
private: System::Windows::Forms::TextBox^ textbox_ODPc;
private: System::Windows::Forms::TextBox^ textbox_ODPa;
private: System::Windows::Forms::TextBox^ textbox_Kc;
private: System::Windows::Forms::TextBox^ textbox_Ka;
private: System::Windows::Forms::TextBox^ textbox_USc;
private: System::Windows::Forms::TextBox^ textbox_USa;
private: System::Windows::Forms::PictureBox^ hero_pb;
private: System::Windows::Forms::MenuStrip^ manu_creator;
private: System::Windows::Forms::ToolStripMenuItem^ menuToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ saveAllToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ clearAllToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ closeFormToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ randomAllToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ heroOptionsToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ saveToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ clearToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ randomToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ heroDescriptionToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ saveToolStripMenuItem1;
private: System::Windows::Forms::ToolStripMenuItem^ clearToolStripMenuItem1;
private: System::Windows::Forms::ToolStripMenuItem^ randomStatsToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ featuresToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ saveToolStripMenuItem2;
private: System::Windows::Forms::ToolStripMenuItem^ clearToolStripMenuItem2;
private: System::Windows::Forms::ToolStripMenuItem^ randomToolStripMenuItem1;
private: System::Windows::Forms::ToolStripMenuItem^ armorPointsToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ saveToolStripMenuItem3;
private: System::Windows::Forms::ToolStripMenuItem^ clearToolStripMenuItem3;
private: System::Windows::Forms::ToolStripMenuItem^ randomStatsToolStripMenuItem1;
private: System::Windows::Forms::ToolStripMenuItem^ choseFileToolStripMenuItem;
private: System::Windows::Forms::PictureBox^ sword_WW;
private: System::Windows::Forms::PictureBox^ sword_ODP;
private: System::Windows::Forms::PictureBox^ sword_ZR;
private: System::Windows::Forms::PictureBox^ sword_INT;
private: System::Windows::Forms::PictureBox^ sword_SW;
private: System::Windows::Forms::PictureBox^ sword_OGD;
private: System::Windows::Forms::PictureBox^ sword_K;
private: System::Windows::Forms::PictureBox^ sword_US;
private: System::Windows::Forms::PictureBox^ welcome_pb;
private: System::Windows::Forms::PictureBox^ pictureBox_plus1;
private: System::Windows::Forms::PictureBox^ pictureBox_minus1;
private: System::Windows::Forms::PictureBox^ pictureBox16;
private: System::Windows::Forms::Label^ label1;
private: System::Windows::Forms::PictureBox^ pictureBox_minus2;
private: System::Windows::Forms::PictureBox^ pictureBox_plus2;
private: System::Windows::Forms::PictureBox^ pictureBox_minus8;
private: System::Windows::Forms::PictureBox^ pictureBox_plus8;
private: System::Windows::Forms::PictureBox^ pictureBox_minus7;
private: System::Windows::Forms::PictureBox^ pictureBox_plus7;
private: System::Windows::Forms::PictureBox^ pictureBox_minus6;
private: System::Windows::Forms::PictureBox^ pictureBox_plus6;
private: System::Windows::Forms::PictureBox^ pictureBox_minus5;
private: System::Windows::Forms::PictureBox^ pictureBox_plus5;
private: System::Windows::Forms::PictureBox^ pictureBox_minus4;
private: System::Windows::Forms::PictureBox^ pictureBox_plus4;
private: System::Windows::Forms::PictureBox^ pictureBox_minus3;
private: System::Windows::Forms::PictureBox^ pictureBox_plus3;
private: System::Windows::Forms::PictureBox^ pictureBox_minus16;
private: System::Windows::Forms::PictureBox^ pictureBox_plus16;
private: System::Windows::Forms::PictureBox^ pictureBox_minus15;
private: System::Windows::Forms::PictureBox^ pictureBox_plus15;
private: System::Windows::Forms::PictureBox^ pictureBox_minus14;
private: System::Windows::Forms::PictureBox^ pictureBox_plus14;
private: System::Windows::Forms::PictureBox^ pictureBox_minus13;
private: System::Windows::Forms::PictureBox^ pictureBox_plus13;
private: System::Windows::Forms::PictureBox^ pictureBox_minus12;
private: System::Windows::Forms::PictureBox^ pictureBox_plus12;
private: System::Windows::Forms::PictureBox^ pictureBox_minus11;
private: System::Windows::Forms::PictureBox^ pictureBox_plus11;
private: System::Windows::Forms::PictureBox^ pictureBox_minus10;
private: System::Windows::Forms::PictureBox^ pictureBox_plus10;
private: System::Windows::Forms::PictureBox^ pictureBox_minus9;
private: System::Windows::Forms::PictureBox^ pictureBox_plus9;
private: System::Windows::Forms::ToolStripMenuItem^ openToolStripMenuItem;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void);
#pragma endregion
		
	   //varibale to move form using mouse
	   bool dragging;
	   Point offset;
private: System::Void CreateHero_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	//enable draging get start mouse position
	dragging = true;
	offset.X = e->X;
	offset.Y = e->Y;
}
private: System::Void CreateHero_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	//if draging enebled get current mouse pos
	if (dragging)
	{
		Point mouseposition = PointToScreen(Point(e->X, e->Y));
		Location = Point(mouseposition.X - offset.X, mouseposition.Y - offset.Y);
	}
}
	   //eneble dragging
private: System::Void CreateHero_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	   //varibale to move form using mouse
	   bool dragging2;
	   Point offset2;
	   //get current mouse pos
private: System::Void hero_pb_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	   //if draging enebled get current mouse pos
private: System::Void hero_pb_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	//disable draging
private: System::Void hero_pb_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);

//MENU OPTIONS
	   //clear all
private: System::Void clearAllToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
//close form and ask user about saving cart
private: System::Void closeFormToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
//clear hero
private: System::Void clearToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);

	   //clear hero desc
private: System::Void clearToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e);
	   //clear features
private: System::Void clearToolStripMenuItem2_Click(System::Object^ sender, System::EventArgs^ e);
	   //clear armor points
private: System::Void clearToolStripMenuItem3_Click(System::Object^ sender, System::EventArgs^ e);
	   //boolen to make aproprite space betwen stats 
private:
	bool method;
	   	   //choosing file path
private: System::IO::StreamWriter^ file_writer = nullptr;
public: System::Void choseFileToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	   //save hero

private: System::Void saveAllToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	   //save hero items
private: System::Void saveToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	   //save hero desc items
private: System::Void saveToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void saveToolStripMenuItem2_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void saveToolStripMenuItem3_Click(System::Object^ sender, System::EventArgs^ e);
	
	   //randomaize all stats
	 
private: System::Void randomAllToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
//RANDOM STATS IN DIFRENT PANELS SEPARATELY

private: System::Void randomToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	   //features
private: System::Void randomToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e);
	   //armor points
private: System::Void randomStatsToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void randomStatsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: void CompareAndShowResult(int textbox_int, int comparenumber);
private: System::Void sword_WW_Click(System::Object^ sender, System::EventArgs^ e);
private: void save_text_tofile(String^ text);
private: System::Void sword_US_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void sword_K_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void sword_ODP_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void sword_ZR_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void sword_INT_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void sword_SW_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void sword_OGD_Click(System::Object^ sender, System::EventArgs^ e);
	   //ADD +5 FETURES OR - +5 FEATURES
	   //WW +
private: System::Void pictureBox_plus1_Click(System::Object^ sender, System::EventArgs^ e);
	   //decreamante 5 from feature
	   //WW -
private: System::Void pictureBox_minus1_Click(System::Object^ sender, System::EventArgs^ e);
	   //WW TEXT CHANGED
private: System::Void textbox_WWa_TextChanged(System::Object^ sender, System::EventArgs^ e);
	   //US +
private: System::Void pictureBox_plus2_Click(System::Object^ sender, System::EventArgs^ e);
	   //US -
private: System::Void pictureBox_minus2_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void textbox_USa_TextChanged(System::Object^ sender, System::EventArgs^ e);
	   //K +
private: System::Void pictureBox_plus3_Click(System::Object^ sender, System::EventArgs^ e);
	   //K-
private: System::Void pictureBox_minus3_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void textbox_Ka_TextChanged(System::Object^ sender, System::EventArgs^ e);
	   //ODP +
private: System::Void pictureBox_plus4_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void pictureBox_minus4_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void textbox_ODPa_TextChanged(System::Object^ sender, System::EventArgs^ e);
	   //ZR +
private: System::Void pictureBox_plus5_Click(System::Object^ sender, System::EventArgs^ e);
	   //ZR -
private: System::Void pictureBox_minus5_Click(System::Object^ sender, System::EventArgs^ e);
	   //ZRa text changed
private: System::Void textbox_ZRa_TextChanged(System::Object^ sender, System::EventArgs^ e);
	   //INT +
private: System::Void pictureBox_plus6_Click(System::Object^ sender, System::EventArgs^ e);
	   //INT -
private: System::Void pictureBox_minus6_Click(System::Object^ sender, System::EventArgs^ e);
	   //INa text changed
private: System::Void textbox_INTa_TextChanged(System::Object^ sender, System::EventArgs^ e);
	   //SW +
private: System::Void pictureBox_plus7_Click(System::Object^ sender, System::EventArgs^ e);
	   //SW -
private: System::Void pictureBox_minus7_Click(System::Object^ sender, System::EventArgs^ e);
	   //SWa text changed
private: System::Void textbox_SWa_TextChanged(System::Object^ sender, System::EventArgs^ e);
	//OGD +
private: System::Void pictureBox_plus8_Click(System::Object^ sender, System::EventArgs^ e);
	   //OGD -
private: System::Void pictureBox_minus8_Click(System::Object^ sender, System::EventArgs^ e);
	   //OGDa text changed
private: System::Void textbox_OGDa_TextChanged(System::Object^ sender, System::EventArgs^ e);
	   //A +
private: System::Void pictureBox_plus9_Click(System::Object^ sender, System::EventArgs^ e);
	   //A -
private: System::Void pictureBox_minus9_Click(System::Object^ sender, System::EventArgs^ e);
	   //Aa text changed
private: System::Void textbox_Aa_TextChanged(System::Object^ sender, System::EventArgs^ e);
	   //Zyw +
private: System::Void pictureBox_plus10_Click(System::Object^ sender, System::EventArgs^ e);
	   //Zyw -
private: System::Void pictureBox_minus10_Click(System::Object^ sender, System::EventArgs^ e);
	   //ZYWa text changed
private: System::Void textbox_ZYWa_TextChanged(System::Object^ sender, System::EventArgs^ e);
	   //S +
private: System::Void pictureBox_plus11_Click(System::Object^ sender, System::EventArgs^ e);
	   //S -
private: System::Void pictureBox_minus11_Click(System::Object^ sender, System::EventArgs^ e);
	   //Sa text changed
private: System::Void textbox_Sa_TextChanged(System::Object^ sender, System::EventArgs^ e);
	   //Wt +
private: System::Void pictureBox_plus12_Click(System::Object^ sender, System::EventArgs^ e);
	   //Wt -
private: System::Void pictureBox_minus12_Click(System::Object^ sender, System::EventArgs^ e);
	   //Wt text changed
private: System::Void textbox_WTa_TextChanged(System::Object^ sender, System::EventArgs^ e);
	   //Sz +
private: System::Void pictureBox_plus13_Click(System::Object^ sender, System::EventArgs^ e);
	   //Sz -
private: System::Void pictureBox_minus13_Click(System::Object^ sender, System::EventArgs^ e);
	   //Sz text changed
private: System::Void textbox_SZa_TextChanged(System::Object^ sender, System::EventArgs^ e);
	   //Mag +
private: System::Void pictureBox_plus14_Click(System::Object^ sender, System::EventArgs^ e);
	   //Mag -
private: System::Void pictureBox_minus14_Click(System::Object^ sender, System::EventArgs^ e);
	   //Mag text changed
private: System::Void textbox_MAGa_TextChanged(System::Object^ sender, System::EventArgs^ e);
	   //PO +
private: System::Void pictureBox_plus15_Click(System::Object^ sender, System::EventArgs^ e);
	   //PO -
private: System::Void pictureBox_minus15_Click(System::Object^ sender, System::EventArgs^ e);
	   //POa text changed
private: System::Void textbox_POa_TextChanged(System::Object^ sender, System::EventArgs^ e);
	   //PP +
private: System::Void pictureBox_plus16_Click(System::Object^ sender, System::EventArgs^ e);
	   //PP -
private: System::Void pictureBox_minus16_Click(System::Object^ sender, System::EventArgs^ e);
	   //PPa text changed
private: System::Void textbox_PPa_TextChanged(System::Object^ sender, System::EventArgs^ e);
	   //Open saved hero from choosen file
private: System::Void openToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
};
}
