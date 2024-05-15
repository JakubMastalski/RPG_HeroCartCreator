#include "CreateHero.h"
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
	CreateHero::CreateHero(void)
	{
		InitializeComponent();
		random_number = gcnew Random();
		random_comparenumber = gcnew Random();
		// mens names list
		men_names = gcnew List<String^>();
		men_names->Add("Rudiger");
		men_names->Add("Grombrindal");
		men_names->Add("Throgg");
		men_names->Add("Wulfrik");
		men_names->Add("Volkmar");
		men_names->Add("Tyrion");
		men_names->Add("Alaric");
		men_names->Add("Belegar");
		men_names->Add("Vlad");
		men_names->Add("Azhag");
		men_names->Add("Tyranno");
		men_names->Add("Balthasar");
		men_names->Add("Malekith");
		men_names->Add("Alaric");
		men_names->Add("Felix");
		men_names->Add("Tzar Boris");
		men_names->Add("Gorbad");
		men_names->Add("Borgut");
		men_names->Add("Snorri");
		men_names->Add("Markus");
		men_names->Add("Thorek");

		// womens names list
		women_names = gcnew List<String^>();
		women_names->Add("Isabella");
		women_names->Add("Morrigan");
		women_names->Add("Helena");
		women_names->Add("Eleanor");
		women_names->Add("Freyja");
		women_names->Add("Brunhilde");
		women_names->Add("Isolde");
		women_names->Add("Aurora");
		women_names->Add("Sylvanas");
		women_names->Add("Astrid");
		women_names->Add("Liliana");
		women_names->Add("Guinevere");
		women_names->Add("Elaine");
		women_names->Add("Artemis");
		women_names->Add("Hera");
		women_names->Add("Melisandre");
		women_names->Add("Circe");
		women_names->Add("Medea");
		women_names->Add("Persephone");
		women_names->Add("Maeve");
		women_names->Add("Agnieszka");

		// races names list
		hero_races = gcnew List<String^>();
		hero_races->Add("Human");
		hero_races->Add("Elf");
		hero_races->Add("Dwarf");
		hero_races->Add("Orc");
		hero_races->Add("Undead");
		hero_races->Add("Halfling");

		//hero profession
		hero_profession = gcnew List<String^>();
		hero_profession->Add("Knight");
		hero_profession->Add("Mage");
		hero_profession->Add("Hunter");
		hero_profession->Add("Priest");
		hero_profession->Add("Assassin");
		hero_profession->Add("Warrior");
		hero_profession->Add("Scout");
		hero_profession->Add("Barbarian");
		hero_profession->Add("Necromancer");
		hero_profession->Add("Paladin");
		hero_profession->Add("Witch Hunter");
		hero_profession->Add("Engineer");
		hero_profession->Add("Alchemist");
		hero_profession->Add("Gladiator");
		hero_profession->Add("Warlock");
		hero_profession->Add("Thief");
		hero_profession->Add("Ranger");
		hero_profession->Add("Sorcerer");
		hero_profession->Add("Squire");
		hero_profession->Add("Bard");

		//hero star_sign
		hero_star_sign = gcnew List<String^>();
		hero_star_sign->Add("Bloodmoon");
		hero_star_sign->Add("Warpstorm");
		hero_star_sign->Add("Ironclad");
		hero_star_sign->Add("Screaming Skull");
		hero_star_sign->Add("Wyrm's Tail");
		hero_star_sign->Add("Stormcaller");

		//hero place_of_birth

		List<String^>^ hero_placeofbirth = gcnew List<String^>();
		hero_placeofbirth->Add("The Blackened Peaks");
		hero_placeofbirth->Add("The Forbidden Marshes");
		hero_placeofbirth->Add("The Ashen Wastes");
		hero_placeofbirth->Add("The Obsidian Spire");
		hero_placeofbirth->Add("The Ruined City of Ancients");
		hero_placeofbirth->Add("The Fertile Plains of Plenty");

		//test main stats default -1 to hit invalid condidion
		WW = -1, US = -1, K = -1, ODP = -1, ZR = -1, INT = -1, SW = -1, OGD = -1;

		//test secondary stats default -1 to hit invalid condidion
		A = -1, ZYW = -1, S = -1, WT = -1, SZ = -1, MAG = -1, PO = -1, PP = -1;

		//random stats
		race_index=0;
		random_age=0;
		age_str="";
		random_height=0;
		height_str="";
		random_weight=0;
		weight_str="";
		siblings=0;
		siblings_str="";
		features=0;
		


		components = gcnew System::ComponentModel::Container();
	}
	CreateHero::~CreateHero()
	{
		if (components)
		{
			if (components)
			{
				delete components;
			}
			if (file_writer != nullptr)
			{
				file_writer->Close();
			}
		}
	}

	void CreateHero::InitializeComponent()
	{
		this->panel_hero1 = (gcnew System::Windows::Forms::Panel());
		this->label_prev_profession = (gcnew System::Windows::Forms::Label());
		this->label_cur_profesion = (gcnew System::Windows::Forms::Label());
		this->label_race = (gcnew System::Windows::Forms::Label());
		this->label_name = (gcnew System::Windows::Forms::Label());
		this->textbox_prev_prof = (gcnew System::Windows::Forms::TextBox());
		this->textbox_cur_prof = (gcnew System::Windows::Forms::TextBox());
		this->textbox_race = (gcnew System::Windows::Forms::TextBox());
		this->textbox_name = (gcnew System::Windows::Forms::TextBox());
		this->panel2 = (gcnew System::Windows::Forms::Panel());
		this->hero_label = (gcnew System::Windows::Forms::Label());
		this->panel_herodesc = (gcnew System::Windows::Forms::Panel());
		this->textbox_birthplace = (gcnew System::Windows::Forms::TextBox());
		this->textbox_siblings = (gcnew System::Windows::Forms::TextBox());
		this->textbox_weight = (gcnew System::Windows::Forms::TextBox());
		this->textbox_height = (gcnew System::Windows::Forms::TextBox());
		this->textbox_star_sign = (gcnew System::Windows::Forms::TextBox());
		this->textbox_sex = (gcnew System::Windows::Forms::TextBox());
		this->label8 = (gcnew System::Windows::Forms::Label());
		this->label9 = (gcnew System::Windows::Forms::Label());
		this->label10 = (gcnew System::Windows::Forms::Label());
		this->label11 = (gcnew System::Windows::Forms::Label());
		this->label12 = (gcnew System::Windows::Forms::Label());
		this->textbox_age = (gcnew System::Windows::Forms::TextBox());
		this->panel_hero_description = (gcnew System::Windows::Forms::Panel());
		this->label_hero_description = (gcnew System::Windows::Forms::Label());
		this->panel7 = (gcnew System::Windows::Forms::Panel());
		this->label14 = (gcnew System::Windows::Forms::Label());
		this->label15 = (gcnew System::Windows::Forms::Label());
		this->panel_images = (gcnew System::Windows::Forms::Panel());
		this->welcome_pb = (gcnew System::Windows::Forms::PictureBox());
		this->panel_hero_img = (gcnew System::Windows::Forms::Panel());
		this->label7 = (gcnew System::Windows::Forms::Label());
		this->label6 = (gcnew System::Windows::Forms::Label());
		this->label5 = (gcnew System::Windows::Forms::Label());
		this->label4 = (gcnew System::Windows::Forms::Label());
		this->label3 = (gcnew System::Windows::Forms::Label());
		this->label2 = (gcnew System::Windows::Forms::Label());
		this->label_armor_points = (gcnew System::Windows::Forms::Label());
		this->tb_leftfootarrmor = (gcnew System::Windows::Forms::TextBox());
		this->tb_rightfarmor = (gcnew System::Windows::Forms::TextBox());
		this->tb_lefthandarmor = (gcnew System::Windows::Forms::TextBox());
		this->tb_rhandarmor = (gcnew System::Windows::Forms::TextBox());
		this->tb_bodyarmor = (gcnew System::Windows::Forms::TextBox());
		this->tb_headarmor = (gcnew System::Windows::Forms::TextBox());
		this->hero_pb = (gcnew System::Windows::Forms::PictureBox());
		this->panel_feat = (gcnew System::Windows::Forms::Panel());
		this->pictureBox_minus16 = (gcnew System::Windows::Forms::PictureBox());
		this->pictureBox_plus16 = (gcnew System::Windows::Forms::PictureBox());
		this->pictureBox_minus15 = (gcnew System::Windows::Forms::PictureBox());
		this->pictureBox_plus15 = (gcnew System::Windows::Forms::PictureBox());
		this->pictureBox_minus14 = (gcnew System::Windows::Forms::PictureBox());
		this->pictureBox_plus14 = (gcnew System::Windows::Forms::PictureBox());
		this->pictureBox_minus13 = (gcnew System::Windows::Forms::PictureBox());
		this->pictureBox_plus13 = (gcnew System::Windows::Forms::PictureBox());
		this->pictureBox_minus12 = (gcnew System::Windows::Forms::PictureBox());
		this->pictureBox_plus12 = (gcnew System::Windows::Forms::PictureBox());
		this->pictureBox_minus11 = (gcnew System::Windows::Forms::PictureBox());
		this->pictureBox_plus11 = (gcnew System::Windows::Forms::PictureBox());
		this->pictureBox_minus10 = (gcnew System::Windows::Forms::PictureBox());
		this->pictureBox_plus10 = (gcnew System::Windows::Forms::PictureBox());
		this->pictureBox_minus9 = (gcnew System::Windows::Forms::PictureBox());
		this->pictureBox_plus9 = (gcnew System::Windows::Forms::PictureBox());
		this->pictureBox_minus8 = (gcnew System::Windows::Forms::PictureBox());
		this->pictureBox_plus8 = (gcnew System::Windows::Forms::PictureBox());
		this->pictureBox_minus7 = (gcnew System::Windows::Forms::PictureBox());
		this->pictureBox_plus7 = (gcnew System::Windows::Forms::PictureBox());
		this->pictureBox_minus6 = (gcnew System::Windows::Forms::PictureBox());
		this->pictureBox_plus6 = (gcnew System::Windows::Forms::PictureBox());
		this->pictureBox_minus5 = (gcnew System::Windows::Forms::PictureBox());
		this->pictureBox_plus5 = (gcnew System::Windows::Forms::PictureBox());
		this->pictureBox_minus4 = (gcnew System::Windows::Forms::PictureBox());
		this->pictureBox_plus4 = (gcnew System::Windows::Forms::PictureBox());
		this->pictureBox_minus3 = (gcnew System::Windows::Forms::PictureBox());
		this->pictureBox_plus3 = (gcnew System::Windows::Forms::PictureBox());
		this->pictureBox_minus2 = (gcnew System::Windows::Forms::PictureBox());
		this->pictureBox_plus2 = (gcnew System::Windows::Forms::PictureBox());
		this->label1 = (gcnew System::Windows::Forms::Label());
		this->sword_ODP = (gcnew System::Windows::Forms::PictureBox());
		this->sword_ZR = (gcnew System::Windows::Forms::PictureBox());
		this->sword_INT = (gcnew System::Windows::Forms::PictureBox());
		this->sword_SW = (gcnew System::Windows::Forms::PictureBox());
		this->sword_OGD = (gcnew System::Windows::Forms::PictureBox());
		this->pictureBox_minus1 = (gcnew System::Windows::Forms::PictureBox());
		this->pictureBox_plus1 = (gcnew System::Windows::Forms::PictureBox());
		this->sword_K = (gcnew System::Windows::Forms::PictureBox());
		this->sword_US = (gcnew System::Windows::Forms::PictureBox());
		this->textbox_PPc = (gcnew System::Windows::Forms::TextBox());
		this->textbox_POc = (gcnew System::Windows::Forms::TextBox());
		this->sword_WW = (gcnew System::Windows::Forms::PictureBox());
		this->textbox_PPa = (gcnew System::Windows::Forms::TextBox());
		this->textbox_POa = (gcnew System::Windows::Forms::TextBox());
		this->textbox_MAGc = (gcnew System::Windows::Forms::TextBox());
		this->textbox_MAGa = (gcnew System::Windows::Forms::TextBox());
		this->textbox_SZc = (gcnew System::Windows::Forms::TextBox());
		this->textbox_SZa = (gcnew System::Windows::Forms::TextBox());
		this->textbox_WTc = (gcnew System::Windows::Forms::TextBox());
		this->textbox_WTa = (gcnew System::Windows::Forms::TextBox());
		this->textbox_Sc = (gcnew System::Windows::Forms::TextBox());
		this->textbox_Sa = (gcnew System::Windows::Forms::TextBox());
		this->textbox_ZYWc = (gcnew System::Windows::Forms::TextBox());
		this->textbox_Aa = (gcnew System::Windows::Forms::TextBox());
		this->textbox_OGDc = (gcnew System::Windows::Forms::TextBox());
		this->textbox_OGDa = (gcnew System::Windows::Forms::TextBox());
		this->textbox_SWc = (gcnew System::Windows::Forms::TextBox());
		this->textbox_SWa = (gcnew System::Windows::Forms::TextBox());
		this->textbox_Ac = (gcnew System::Windows::Forms::TextBox());
		this->textbox_INTc = (gcnew System::Windows::Forms::TextBox());
		this->textbox_INTa = (gcnew System::Windows::Forms::TextBox());
		this->textbox_ZYWa = (gcnew System::Windows::Forms::TextBox());
		this->textbox_ZRc = (gcnew System::Windows::Forms::TextBox());
		this->textbox_ZRa = (gcnew System::Windows::Forms::TextBox());
		this->textbox_ODPc = (gcnew System::Windows::Forms::TextBox());
		this->textbox_ODPa = (gcnew System::Windows::Forms::TextBox());
		this->textbox_Kc = (gcnew System::Windows::Forms::TextBox());
		this->textbox_Ka = (gcnew System::Windows::Forms::TextBox());
		this->textbox_USc = (gcnew System::Windows::Forms::TextBox());
		this->textbox_USa = (gcnew System::Windows::Forms::TextBox());
		this->textbox_WWc = (gcnew System::Windows::Forms::TextBox());
		this->textbox_WWa = (gcnew System::Windows::Forms::TextBox());
		this->label_PP = (gcnew System::Windows::Forms::Label());
		this->label_PO = (gcnew System::Windows::Forms::Label());
		this->label_MAG = (gcnew System::Windows::Forms::Label());
		this->label_SZ = (gcnew System::Windows::Forms::Label());
		this->label_WT = (gcnew System::Windows::Forms::Label());
		this->label_S = (gcnew System::Windows::Forms::Label());
		this->label_ZYW = (gcnew System::Windows::Forms::Label());
		this->label_A = (gcnew System::Windows::Forms::Label());
		this->label32 = (gcnew System::Windows::Forms::Label());
		this->label_K = (gcnew System::Windows::Forms::Label());
		this->label_SW = (gcnew System::Windows::Forms::Label());
		this->label_INT = (gcnew System::Windows::Forms::Label());
		this->label_ZR = (gcnew System::Windows::Forms::Label());
		this->label_OGD = (gcnew System::Windows::Forms::Label());
		this->label_US = (gcnew System::Windows::Forms::Label());
		this->label_WW = (gcnew System::Windows::Forms::Label());
		this->label_current2 = (gcnew System::Windows::Forms::Label());
		this->label_initial2 = (gcnew System::Windows::Forms::Label());
		this->label_secondary = (gcnew System::Windows::Forms::Label());
		this->label_current1 = (gcnew System::Windows::Forms::Label());
		this->label_development1 = (gcnew System::Windows::Forms::Label());
		this->label_initial1 = (gcnew System::Windows::Forms::Label());
		this->label_featuresmain = (gcnew System::Windows::Forms::Label());
		this->panel_features = (gcnew System::Windows::Forms::Panel());
		this->features_label = (gcnew System::Windows::Forms::Label());
		this->pictureBox16 = (gcnew System::Windows::Forms::PictureBox());
		this->manu_creator = (gcnew System::Windows::Forms::MenuStrip());
		this->menuToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->choseFileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->randomAllToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->saveAllToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->clearAllToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->closeFormToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->heroOptionsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->clearToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->randomToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->heroDescriptionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->saveToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->clearToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->randomStatsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->featuresToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->saveToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->clearToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->randomToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->armorPointsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->saveToolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->clearToolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->randomStatsToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->panel_hero1->SuspendLayout();
		this->panel2->SuspendLayout();
		this->panel_herodesc->SuspendLayout();
		this->panel_hero_description->SuspendLayout();
		this->panel_images->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->welcome_pb))->BeginInit();
		this->panel_hero_img->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->hero_pb))->BeginInit();
		this->panel_feat->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_minus16))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_plus16))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_minus15))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_plus15))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_minus14))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_plus14))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_minus13))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_plus13))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_minus12))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_plus12))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_minus11))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_plus11))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_minus10))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_plus10))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_minus9))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_plus9))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_minus8))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_plus8))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_minus7))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_plus7))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_minus6))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_plus6))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_minus5))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_plus5))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_minus4))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_plus4))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_minus3))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_plus3))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_minus2))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_plus2))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sword_ODP))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sword_ZR))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sword_INT))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sword_SW))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sword_OGD))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_minus1))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_plus1))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sword_K))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sword_US))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sword_WW))->BeginInit();
		this->panel_features->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox16))->BeginInit();
		this->manu_creator->SuspendLayout();
		this->SuspendLayout();
		// 
		// panel_hero1
		// 
		this->panel_hero1->BackColor = System::Drawing::Color::White;
		this->panel_hero1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
		this->panel_hero1->Controls->Add(this->label_prev_profession);
		this->panel_hero1->Controls->Add(this->label_cur_profesion);
		this->panel_hero1->Controls->Add(this->label_race);
		this->panel_hero1->Controls->Add(this->label_name);
		this->panel_hero1->Controls->Add(this->textbox_prev_prof);
		this->panel_hero1->Controls->Add(this->textbox_cur_prof);
		this->panel_hero1->Controls->Add(this->textbox_race);
		this->panel_hero1->Controls->Add(this->textbox_name);
		this->panel_hero1->Controls->Add(this->panel2);
		this->panel_hero1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->panel_hero1->Location = System::Drawing::Point(8, 45);
		this->panel_hero1->Name = L"panel_hero1";
		this->panel_hero1->Size = System::Drawing::Size(541, 223);
		this->panel_hero1->TabIndex = 3;
		// 
		// label_prev_profession
		// 
		this->label_prev_profession->AutoSize = true;
		this->label_prev_profession->Font = (gcnew System::Drawing::Font(L"Georgia", 7.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->label_prev_profession->Location = System::Drawing::Point(4, 164);
		this->label_prev_profession->Name = L"label_prev_profession";
		this->label_prev_profession->Size = System::Drawing::Size(138, 15);
		this->label_prev_profession->TabIndex = 8;
		this->label_prev_profession->Text = L"Previous Profession:";
		// 
		// label_cur_profesion
		// 
		this->label_cur_profesion->AutoSize = true;
		this->label_cur_profesion->Font = (gcnew System::Drawing::Font(L"Georgia", 7.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->label_cur_profesion->Location = System::Drawing::Point(4, 125);
		this->label_cur_profesion->Name = L"label_cur_profesion";
		this->label_cur_profesion->Size = System::Drawing::Size(135, 15);
		this->label_cur_profesion->TabIndex = 7;
		this->label_cur_profesion->Text = L"Current Profession:";
		// 
		// label_race
		// 
		this->label_race->AutoSize = true;
		this->label_race->Font = (gcnew System::Drawing::Font(L"Georgia", 7.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->label_race->Location = System::Drawing::Point(4, 85);
		this->label_race->Name = L"label_race";
		this->label_race->Size = System::Drawing::Size(42, 15);
		this->label_race->TabIndex = 6;
		this->label_race->Text = L"Race:";
		// 
		// label_name
		// 
		this->label_name->AutoSize = true;
		this->label_name->Font = (gcnew System::Drawing::Font(L"Georgia", 7.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->label_name->Location = System::Drawing::Point(4, 45);
		this->label_name->Name = L"label_name";
		this->label_name->Size = System::Drawing::Size(49, 15);
		this->label_name->TabIndex = 5;
		this->label_name->Text = L"Name:";
		// 
		// textbox_prev_prof
		// 
		this->textbox_prev_prof->Font = (gcnew System::Drawing::Font(L"Georgia", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->textbox_prev_prof->Location = System::Drawing::Point(165, 159);
		this->textbox_prev_prof->Multiline = true;
		this->textbox_prev_prof->Name = L"textbox_prev_prof";
		this->textbox_prev_prof->Size = System::Drawing::Size(360, 33);
		this->textbox_prev_prof->TabIndex = 4;
		// 
		// textbox_cur_prof
		// 
		this->textbox_cur_prof->Font = (gcnew System::Drawing::Font(L"Georgia", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->textbox_cur_prof->Location = System::Drawing::Point(165, 120);
		this->textbox_cur_prof->Multiline = true;
		this->textbox_cur_prof->Name = L"textbox_cur_prof";
		this->textbox_cur_prof->Size = System::Drawing::Size(360, 33);
		this->textbox_cur_prof->TabIndex = 3;
		// 
		// textbox_race
		// 
		this->textbox_race->Font = (gcnew System::Drawing::Font(L"Georgia", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->textbox_race->Location = System::Drawing::Point(59, 81);
		this->textbox_race->Multiline = true;
		this->textbox_race->Name = L"textbox_race";
		this->textbox_race->Size = System::Drawing::Size(466, 33);
		this->textbox_race->TabIndex = 2;
		// 
		// textbox_name
		// 
		this->textbox_name->Font = (gcnew System::Drawing::Font(L"Georgia", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->textbox_name->Location = System::Drawing::Point(59, 45);
		this->textbox_name->Multiline = true;
		this->textbox_name->Name = L"textbox_name";
		this->textbox_name->Size = System::Drawing::Size(466, 30);
		this->textbox_name->TabIndex = 1;
		// 
		// panel2
		// 
		this->panel2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
			| System::Windows::Forms::AnchorStyles::Right));
		this->panel2->BackColor = System::Drawing::Color::Black;
		this->panel2->Controls->Add(this->hero_label);
		this->panel2->Location = System::Drawing::Point(-1, 1);
		this->panel2->Name = L"panel2";
		this->panel2->Size = System::Drawing::Size(541, 41);
		this->panel2->TabIndex = 0;
		// 
		// hero_label
		// 
		this->hero_label->AutoSize = true;
		this->hero_label->BackColor = System::Drawing::Color::Black;
		this->hero_label->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		this->hero_label->Font = (gcnew System::Drawing::Font(L"Georgia", 20, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
		this->hero_label->ForeColor = System::Drawing::Color::White;
		this->hero_label->Location = System::Drawing::Point(180, 0);
		this->hero_label->Name = L"hero_label";
		this->hero_label->Size = System::Drawing::Size(128, 39);
		this->hero_label->TabIndex = 4;
		this->hero_label->Text = L"HERO";
		// 
		// panel_herodesc
		// 
		this->panel_herodesc->BackColor = System::Drawing::Color::White;
		this->panel_herodesc->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
		this->panel_herodesc->Controls->Add(this->textbox_birthplace);
		this->panel_herodesc->Controls->Add(this->textbox_siblings);
		this->panel_herodesc->Controls->Add(this->textbox_weight);
		this->panel_herodesc->Controls->Add(this->textbox_height);
		this->panel_herodesc->Controls->Add(this->textbox_star_sign);
		this->panel_herodesc->Controls->Add(this->textbox_sex);
		this->panel_herodesc->Controls->Add(this->label8);
		this->panel_herodesc->Controls->Add(this->label9);
		this->panel_herodesc->Controls->Add(this->label10);
		this->panel_herodesc->Controls->Add(this->label11);
		this->panel_herodesc->Controls->Add(this->label12);
		this->panel_herodesc->Controls->Add(this->textbox_age);
		this->panel_herodesc->Controls->Add(this->panel_hero_description);
		this->panel_herodesc->Controls->Add(this->label14);
		this->panel_herodesc->Controls->Add(this->label15);
		this->panel_herodesc->Location = System::Drawing::Point(7, 295);
		this->panel_herodesc->Name = L"panel_herodesc";
		this->panel_herodesc->Size = System::Drawing::Size(543, 214);
		this->panel_herodesc->TabIndex = 17;
		// 
		// textbox_birthplace
		// 
		this->textbox_birthplace->Font = (gcnew System::Drawing::Font(L"Georgia", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->textbox_birthplace->Location = System::Drawing::Point(237, 163);
		this->textbox_birthplace->Multiline = true;
		this->textbox_birthplace->Name = L"textbox_birthplace";
		this->textbox_birthplace->Size = System::Drawing::Size(289, 30);
		this->textbox_birthplace->TabIndex = 16;
		// 
		// textbox_siblings
		// 
		this->textbox_siblings->Font = (gcnew System::Drawing::Font(L"Georgia", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->textbox_siblings->Location = System::Drawing::Point(307, 86);
		this->textbox_siblings->Multiline = true;
		this->textbox_siblings->Name = L"textbox_siblings";
		this->textbox_siblings->Size = System::Drawing::Size(217, 30);
		this->textbox_siblings->TabIndex = 15;
		// 
		// textbox_weight
		// 
		this->textbox_weight->Font = (gcnew System::Drawing::Font(L"Georgia", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->textbox_weight->Location = System::Drawing::Point(70, 163);
		this->textbox_weight->Multiline = true;
		this->textbox_weight->Name = L"textbox_weight";
		this->textbox_weight->Size = System::Drawing::Size(158, 30);
		this->textbox_weight->TabIndex = 14;
		// 
		// textbox_height
		// 
		this->textbox_height->Font = (gcnew System::Drawing::Font(L"Georgia", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->textbox_height->Location = System::Drawing::Point(70, 122);
		this->textbox_height->Multiline = true;
		this->textbox_height->Name = L"textbox_height";
		this->textbox_height->Size = System::Drawing::Size(158, 33);
		this->textbox_height->TabIndex = 13;
		// 
		// textbox_star_sign
		// 
		this->textbox_star_sign->Font = (gcnew System::Drawing::Font(L"Georgia", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->textbox_star_sign->Location = System::Drawing::Point(307, 43);
		this->textbox_star_sign->Multiline = true;
		this->textbox_star_sign->Name = L"textbox_star_sign";
		this->textbox_star_sign->Size = System::Drawing::Size(217, 30);
		this->textbox_star_sign->TabIndex = 1;
		// 
		// textbox_sex
		// 
		this->textbox_sex->Font = (gcnew System::Drawing::Font(L"Georgia", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->textbox_sex->Location = System::Drawing::Point(46, 83);
		this->textbox_sex->Multiline = true;
		this->textbox_sex->Name = L"textbox_sex";
		this->textbox_sex->Size = System::Drawing::Size(182, 33);
		this->textbox_sex->TabIndex = 12;
		// 
		// label8
		// 
		this->label8->AutoSize = true;
		this->label8->Font = (gcnew System::Drawing::Font(L"Georgia", 7.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->label8->Location = System::Drawing::Point(234, 126);
		this->label8->Name = L"label8";
		this->label8->Size = System::Drawing::Size(98, 15);
		this->label8->TabIndex = 11;
		this->label8->Text = L"Place of birth:";
		// 
		// label9
		// 
		this->label9->AutoSize = true;
		this->label9->Font = (gcnew System::Drawing::Font(L"Georgia", 7.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->label9->Location = System::Drawing::Point(232, 86);
		this->label9->Name = L"label9";
		this->label9->Size = System::Drawing::Size(64, 15);
		this->label9->TabIndex = 8;
		this->label9->Text = L"Siblings:";
		// 
		// label10
		// 
		this->label10->AutoSize = true;
		this->label10->Font = (gcnew System::Drawing::Font(L"Georgia", 7.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->label10->Location = System::Drawing::Point(232, 46);
		this->label10->Name = L"label10";
		this->label10->Size = System::Drawing::Size(72, 15);
		this->label10->TabIndex = 10;
		this->label10->Text = L"Star Sign:";
		// 
		// label11
		// 
		this->label11->AutoSize = true;
		this->label11->Font = (gcnew System::Drawing::Font(L"Georgia", 7.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->label11->Location = System::Drawing::Point(3, 83);
		this->label11->Name = L"label11";
		this->label11->Size = System::Drawing::Size(34, 15);
		this->label11->TabIndex = 9;
		this->label11->Text = L"Sex:";
		// 
		// label12
		// 
		this->label12->AutoSize = true;
		this->label12->Font = (gcnew System::Drawing::Font(L"Georgia", 7.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->label12->Location = System::Drawing::Point(3, 43);
		this->label12->Name = L"label12";
		this->label12->Size = System::Drawing::Size(35, 15);
		this->label12->TabIndex = 5;
		this->label12->Text = L"Age:";
		// 
		// textbox_age
		// 
		this->textbox_age->Font = (gcnew System::Drawing::Font(L"Georgia", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->textbox_age->Location = System::Drawing::Point(46, 43);
		this->textbox_age->Multiline = true;
		this->textbox_age->Name = L"textbox_age";
		this->textbox_age->Size = System::Drawing::Size(182, 32);
		this->textbox_age->TabIndex = 3;
		// 
		// panel_hero_description
		// 
		this->panel_hero_description->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
			| System::Windows::Forms::AnchorStyles::Right));
		this->panel_hero_description->BackColor = System::Drawing::Color::Black;
		this->panel_hero_description->Controls->Add(this->label_hero_description);
		this->panel_hero_description->Controls->Add(this->panel7);
		this->panel_hero_description->Location = System::Drawing::Point(0, -1);
		this->panel_hero_description->Name = L"panel_hero_description";
		this->panel_hero_description->Size = System::Drawing::Size(543, 44);
		this->panel_hero_description->TabIndex = 0;
		// 
		// label_hero_description
		// 
		this->label_hero_description->AutoSize = true;
		this->label_hero_description->BackColor = System::Drawing::Color::Black;
		this->label_hero_description->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		this->label_hero_description->Font = (gcnew System::Drawing::Font(L"Georgia", 20, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
		this->label_hero_description->ForeColor = System::Drawing::Color::White;
		this->label_hero_description->Location = System::Drawing::Point(75, 2);
		this->label_hero_description->Name = L"label_hero_description";
		this->label_hero_description->Size = System::Drawing::Size(396, 39);
		this->label_hero_description->TabIndex = 4;
		this->label_hero_description->Text = L"HERO DESCRIPTION";
		// 
		// panel7
		// 
		this->panel7->Location = System::Drawing::Point(225, 41);
		this->panel7->Name = L"panel7";
		this->panel7->Size = System::Drawing::Size(233, 187);
		this->panel7->TabIndex = 9;
		// 
		// label14
		// 
		this->label14->AutoSize = true;
		this->label14->Font = (gcnew System::Drawing::Font(L"Georgia", 7.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->label14->Location = System::Drawing::Point(3, 123);
		this->label14->Name = L"label14";
		this->label14->Size = System::Drawing::Size(56, 15);
		this->label14->TabIndex = 7;
		this->label14->Text = L"Height:";
		// 
		// label15
		// 
		this->label15->AutoSize = true;
		this->label15->Font = (gcnew System::Drawing::Font(L"Georgia", 7.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->label15->Location = System::Drawing::Point(3, 163);
		this->label15->Name = L"label15";
		this->label15->Size = System::Drawing::Size(59, 15);
		this->label15->TabIndex = 6;
		this->label15->Text = L"Weight:";
		// 
		// panel_images
		// 
		this->panel_images->Controls->Add(this->welcome_pb);
		this->panel_images->Location = System::Drawing::Point(560, 29);
		this->panel_images->Name = L"panel_images";
		this->panel_images->Size = System::Drawing::Size(552, 145);
		this->panel_images->TabIndex = 11;
		// 
		// welcome_pb
		// 
		this->welcome_pb->Dock = System::Windows::Forms::DockStyle::Fill;
		this->welcome_pb->ImageLocation = L"C:\\Users\\USER\\Desktop\\Warhamer_UI\\img\\logo.jpg";
		this->welcome_pb->Location = System::Drawing::Point(0, 0);
		this->welcome_pb->Name = L"welcome_pb";
		this->welcome_pb->Size = System::Drawing::Size(552, 145);
		this->welcome_pb->TabIndex = 5;
		this->welcome_pb->TabStop = false;
		// 
		// panel_hero_img
		// 
		this->panel_hero_img->Controls->Add(this->label7);
		this->panel_hero_img->Controls->Add(this->label6);
		this->panel_hero_img->Controls->Add(this->label5);
		this->panel_hero_img->Controls->Add(this->label4);
		this->panel_hero_img->Controls->Add(this->label3);
		this->panel_hero_img->Controls->Add(this->label2);
		this->panel_hero_img->Controls->Add(this->label_armor_points);
		this->panel_hero_img->Controls->Add(this->tb_leftfootarrmor);
		this->panel_hero_img->Controls->Add(this->tb_rightfarmor);
		this->panel_hero_img->Controls->Add(this->tb_lefthandarmor);
		this->panel_hero_img->Controls->Add(this->tb_rhandarmor);
		this->panel_hero_img->Controls->Add(this->tb_bodyarmor);
		this->panel_hero_img->Controls->Add(this->tb_headarmor);
		this->panel_hero_img->Controls->Add(this->hero_pb);
		this->panel_hero_img->Location = System::Drawing::Point(557, 180);
		this->panel_hero_img->Name = L"panel_hero_img";
		this->panel_hero_img->Size = System::Drawing::Size(552, 689);
		this->panel_hero_img->TabIndex = 12;
		// 
		// label7
		// 
		this->label7->AutoSize = true;
		this->label7->BackColor = System::Drawing::Color::White;
		this->label7->Font = (gcnew System::Drawing::Font(L"Georgia", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->label7->Location = System::Drawing::Point(446, 573);
		this->label7->Name = L"label7";
		this->label7->Size = System::Drawing::Size(72, 16);
		this->label7->TabIndex = 22;
		this->label7->Text = L"Left Foot";
		// 
		// label6
		// 
		this->label6->AutoSize = true;
		this->label6->BackColor = System::Drawing::Color::White;
		this->label6->Font = (gcnew System::Drawing::Font(L"Georgia", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->label6->Location = System::Drawing::Point(27, 573);
		this->label6->Name = L"label6";
		this->label6->Size = System::Drawing::Size(82, 16);
		this->label6->TabIndex = 21;
		this->label6->Text = L"Right Foot";
		// 
		// label5
		// 
		this->label5->AutoSize = true;
		this->label5->BackColor = System::Drawing::Color::White;
		this->label5->Font = (gcnew System::Drawing::Font(L"Georgia", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->label5->Location = System::Drawing::Point(442, 301);
		this->label5->Name = L"label5";
		this->label5->Size = System::Drawing::Size(78, 16);
		this->label5->TabIndex = 20;
		this->label5->Text = L"Left Hand";
		// 
		// label4
		// 
		this->label4->AutoSize = true;
		this->label4->BackColor = System::Drawing::Color::White;
		this->label4->Font = (gcnew System::Drawing::Font(L"Georgia", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->label4->Location = System::Drawing::Point(23, 301);
		this->label4->Name = L"label4";
		this->label4->Size = System::Drawing::Size(88, 16);
		this->label4->TabIndex = 19;
		this->label4->Text = L"Right Hand";
		// 
		// label3
		// 
		this->label3->AutoSize = true;
		this->label3->BackColor = System::Drawing::Color::White;
		this->label3->Font = (gcnew System::Drawing::Font(L"Georgia", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->label3->Location = System::Drawing::Point(456, 56);
		this->label3->Name = L"label3";
		this->label3->Size = System::Drawing::Size(44, 16);
		this->label3->TabIndex = 18;
		this->label3->Text = L"Body";
		// 
		// label2
		// 
		this->label2->AutoSize = true;
		this->label2->BackColor = System::Drawing::Color::White;
		this->label2->Font = (gcnew System::Drawing::Font(L"Georgia", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->label2->Location = System::Drawing::Point(43, 56);
		this->label2->Name = L"label2";
		this->label2->Size = System::Drawing::Size(44, 16);
		this->label2->TabIndex = 17;
		this->label2->Text = L"Head";
		// 
		// label_armor_points
		// 
		this->label_armor_points->AutoSize = true;
		this->label_armor_points->BackColor = System::Drawing::Color::Black;
		this->label_armor_points->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		this->label_armor_points->Font = (gcnew System::Drawing::Font(L"Georgia", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
		this->label_armor_points->ForeColor = System::Drawing::Color::White;
		this->label_armor_points->Location = System::Drawing::Point(201, 5);
		this->label_armor_points->Name = L"label_armor_points";
		this->label_armor_points->Size = System::Drawing::Size(151, 24);
		this->label_armor_points->TabIndex = 5;
		this->label_armor_points->Text = L"Armor Points";
		// 
		// tb_leftfootarrmor
		// 
		this->tb_leftfootarrmor->Font = (gcnew System::Drawing::Font(L"Georgia", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->tb_leftfootarrmor->Location = System::Drawing::Point(474, 608);
		this->tb_leftfootarrmor->Name = L"tb_leftfootarrmor";
		this->tb_leftfootarrmor->Size = System::Drawing::Size(28, 25);
		this->tb_leftfootarrmor->TabIndex = 6;
		// 
		// tb_rightfarmor
		// 
		this->tb_rightfarmor->Font = (gcnew System::Drawing::Font(L"Georgia", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->tb_rightfarmor->Location = System::Drawing::Point(51, 608);
		this->tb_rightfarmor->Name = L"tb_rightfarmor";
		this->tb_rightfarmor->Size = System::Drawing::Size(28, 25);
		this->tb_rightfarmor->TabIndex = 5;
		// 
		// tb_lefthandarmor
		// 
		this->tb_lefthandarmor->Font = (gcnew System::Drawing::Font(L"Georgia", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->tb_lefthandarmor->Location = System::Drawing::Point(474, 341);
		this->tb_lefthandarmor->Name = L"tb_lefthandarmor";
		this->tb_lefthandarmor->Size = System::Drawing::Size(28, 25);
		this->tb_lefthandarmor->TabIndex = 4;
		// 
		// tb_rhandarmor
		// 
		this->tb_rhandarmor->Font = (gcnew System::Drawing::Font(L"Georgia", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->tb_rhandarmor->Location = System::Drawing::Point(51, 341);
		this->tb_rhandarmor->Name = L"tb_rhandarmor";
		this->tb_rhandarmor->Size = System::Drawing::Size(28, 25);
		this->tb_rhandarmor->TabIndex = 3;
		// 
		// tb_bodyarmor
		// 
		this->tb_bodyarmor->Font = (gcnew System::Drawing::Font(L"Georgia", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->tb_bodyarmor->Location = System::Drawing::Point(474, 93);
		this->tb_bodyarmor->Name = L"tb_bodyarmor";
		this->tb_bodyarmor->Size = System::Drawing::Size(28, 25);
		this->tb_bodyarmor->TabIndex = 2;
		// 
		// tb_headarmor
		// 
		this->tb_headarmor->Font = (gcnew System::Drawing::Font(L"Georgia", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->tb_headarmor->Location = System::Drawing::Point(51, 93);
		this->tb_headarmor->Name = L"tb_headarmor";
		this->tb_headarmor->Size = System::Drawing::Size(28, 25);
		this->tb_headarmor->TabIndex = 1;
		// 
		// hero_pb
		// 
		this->hero_pb->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
			| System::Windows::Forms::AnchorStyles::Right));
		this->hero_pb->ImageLocation = L"C:\\Users\\USER\\Desktop\\Warhamer_UI\\img\\hero.jpg";
		this->hero_pb->Location = System::Drawing::Point(3, -1);
		this->hero_pb->Name = L"hero_pb";
		this->hero_pb->Size = System::Drawing::Size(412, 567);
		this->hero_pb->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
		this->hero_pb->TabIndex = 0;
		this->hero_pb->TabStop = false;
		this->hero_pb->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &CreateHero::hero_pb_MouseDown);
		this->hero_pb->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &CreateHero::hero_pb_MouseMove);
		this->hero_pb->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &CreateHero::hero_pb_MouseUp);
		// 
		// panel_feat
		// 
		this->panel_feat->BackColor = System::Drawing::Color::White;
		this->panel_feat->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
		this->panel_feat->Controls->Add(this->pictureBox_minus16);
		this->panel_feat->Controls->Add(this->pictureBox_plus16);
		this->panel_feat->Controls->Add(this->pictureBox_minus15);
		this->panel_feat->Controls->Add(this->pictureBox_plus15);
		this->panel_feat->Controls->Add(this->pictureBox_minus14);
		this->panel_feat->Controls->Add(this->pictureBox_plus14);
		this->panel_feat->Controls->Add(this->pictureBox_minus13);
		this->panel_feat->Controls->Add(this->pictureBox_plus13);
		this->panel_feat->Controls->Add(this->pictureBox_minus12);
		this->panel_feat->Controls->Add(this->pictureBox_plus12);
		this->panel_feat->Controls->Add(this->pictureBox_minus11);
		this->panel_feat->Controls->Add(this->pictureBox_plus11);
		this->panel_feat->Controls->Add(this->pictureBox_minus10);
		this->panel_feat->Controls->Add(this->pictureBox_plus10);
		this->panel_feat->Controls->Add(this->pictureBox_minus9);
		this->panel_feat->Controls->Add(this->pictureBox_plus9);
		this->panel_feat->Controls->Add(this->pictureBox_minus8);
		this->panel_feat->Controls->Add(this->pictureBox_plus8);
		this->panel_feat->Controls->Add(this->pictureBox_minus7);
		this->panel_feat->Controls->Add(this->pictureBox_plus7);
		this->panel_feat->Controls->Add(this->pictureBox_minus6);
		this->panel_feat->Controls->Add(this->pictureBox_plus6);
		this->panel_feat->Controls->Add(this->pictureBox_minus5);
		this->panel_feat->Controls->Add(this->pictureBox_plus5);
		this->panel_feat->Controls->Add(this->pictureBox_minus4);
		this->panel_feat->Controls->Add(this->pictureBox_plus4);
		this->panel_feat->Controls->Add(this->pictureBox_minus3);
		this->panel_feat->Controls->Add(this->pictureBox_plus3);
		this->panel_feat->Controls->Add(this->pictureBox_minus2);
		this->panel_feat->Controls->Add(this->pictureBox_plus2);
		this->panel_feat->Controls->Add(this->label1);
		this->panel_feat->Controls->Add(this->sword_ODP);
		this->panel_feat->Controls->Add(this->sword_ZR);
		this->panel_feat->Controls->Add(this->sword_INT);
		this->panel_feat->Controls->Add(this->sword_SW);
		this->panel_feat->Controls->Add(this->sword_OGD);
		this->panel_feat->Controls->Add(this->pictureBox_minus1);
		this->panel_feat->Controls->Add(this->pictureBox_plus1);
		this->panel_feat->Controls->Add(this->sword_K);
		this->panel_feat->Controls->Add(this->sword_US);
		this->panel_feat->Controls->Add(this->textbox_PPc);
		this->panel_feat->Controls->Add(this->textbox_POc);
		this->panel_feat->Controls->Add(this->sword_WW);
		this->panel_feat->Controls->Add(this->textbox_PPa);
		this->panel_feat->Controls->Add(this->textbox_POa);
		this->panel_feat->Controls->Add(this->textbox_MAGc);
		this->panel_feat->Controls->Add(this->textbox_MAGa);
		this->panel_feat->Controls->Add(this->textbox_SZc);
		this->panel_feat->Controls->Add(this->textbox_SZa);
		this->panel_feat->Controls->Add(this->textbox_WTc);
		this->panel_feat->Controls->Add(this->textbox_WTa);
		this->panel_feat->Controls->Add(this->textbox_Sc);
		this->panel_feat->Controls->Add(this->textbox_Sa);
		this->panel_feat->Controls->Add(this->textbox_ZYWc);
		this->panel_feat->Controls->Add(this->textbox_Aa);
		this->panel_feat->Controls->Add(this->textbox_OGDc);
		this->panel_feat->Controls->Add(this->textbox_OGDa);
		this->panel_feat->Controls->Add(this->textbox_SWc);
		this->panel_feat->Controls->Add(this->textbox_SWa);
		this->panel_feat->Controls->Add(this->textbox_Ac);
		this->panel_feat->Controls->Add(this->textbox_INTc);
		this->panel_feat->Controls->Add(this->textbox_INTa);
		this->panel_feat->Controls->Add(this->textbox_ZYWa);
		this->panel_feat->Controls->Add(this->textbox_ZRc);
		this->panel_feat->Controls->Add(this->textbox_ZRa);
		this->panel_feat->Controls->Add(this->textbox_ODPc);
		this->panel_feat->Controls->Add(this->textbox_ODPa);
		this->panel_feat->Controls->Add(this->textbox_Kc);
		this->panel_feat->Controls->Add(this->textbox_Ka);
		this->panel_feat->Controls->Add(this->textbox_USc);
		this->panel_feat->Controls->Add(this->textbox_USa);
		this->panel_feat->Controls->Add(this->textbox_WWc);
		this->panel_feat->Controls->Add(this->textbox_WWa);
		this->panel_feat->Controls->Add(this->label_PP);
		this->panel_feat->Controls->Add(this->label_PO);
		this->panel_feat->Controls->Add(this->label_MAG);
		this->panel_feat->Controls->Add(this->label_SZ);
		this->panel_feat->Controls->Add(this->label_WT);
		this->panel_feat->Controls->Add(this->label_S);
		this->panel_feat->Controls->Add(this->label_ZYW);
		this->panel_feat->Controls->Add(this->label_A);
		this->panel_feat->Controls->Add(this->label32);
		this->panel_feat->Controls->Add(this->label_K);
		this->panel_feat->Controls->Add(this->label_SW);
		this->panel_feat->Controls->Add(this->label_INT);
		this->panel_feat->Controls->Add(this->label_ZR);
		this->panel_feat->Controls->Add(this->label_OGD);
		this->panel_feat->Controls->Add(this->label_US);
		this->panel_feat->Controls->Add(this->label_WW);
		this->panel_feat->Controls->Add(this->label_current2);
		this->panel_feat->Controls->Add(this->label_initial2);
		this->panel_feat->Controls->Add(this->label_secondary);
		this->panel_feat->Controls->Add(this->label_current1);
		this->panel_feat->Controls->Add(this->label_development1);
		this->panel_feat->Controls->Add(this->label_initial1);
		this->panel_feat->Controls->Add(this->label_featuresmain);
		this->panel_feat->Controls->Add(this->panel_features);
		this->panel_feat->Location = System::Drawing::Point(7, 538);
		this->panel_feat->Name = L"panel_feat";
		this->panel_feat->Size = System::Drawing::Size(542, 277);
		this->panel_feat->TabIndex = 9;
		// 
		// pictureBox_minus16
		// 
		this->pictureBox_minus16->Cursor = System::Windows::Forms::Cursors::Hand;
		this->pictureBox_minus16->ImageLocation = L"C:\\Users\\USER\\Desktop\\Warhamer_UI\\img\\minus.jpg";
		this->pictureBox_minus16->Location = System::Drawing::Point(515, 211);
		this->pictureBox_minus16->Name = L"pictureBox_minus16";
		this->pictureBox_minus16->Size = System::Drawing::Size(21, 21);
		this->pictureBox_minus16->TabIndex = 138;
		this->pictureBox_minus16->TabStop = false;
		this->pictureBox_minus16->Click += gcnew System::EventHandler(this, &CreateHero::pictureBox_minus16_Click);
		// 
		// pictureBox_plus16
		// 
		this->pictureBox_plus16->Cursor = System::Windows::Forms::Cursors::Hand;
		this->pictureBox_plus16->ImageLocation = L"C:\\Users\\USER\\Desktop\\Warhamer_UI\\img\\plus.jpg";
		this->pictureBox_plus16->Location = System::Drawing::Point(488, 211);
		this->pictureBox_plus16->Name = L"pictureBox_plus16";
		this->pictureBox_plus16->Size = System::Drawing::Size(21, 21);
		this->pictureBox_plus16->TabIndex = 137;
		this->pictureBox_plus16->TabStop = false;
		this->pictureBox_plus16->Click += gcnew System::EventHandler(this, &CreateHero::pictureBox_plus16_Click);
		// 
		// pictureBox_minus15
		// 
		this->pictureBox_minus15->Cursor = System::Windows::Forms::Cursors::Hand;
		this->pictureBox_minus15->ImageLocation = L"C:\\Users\\USER\\Desktop\\Warhamer_UI\\img\\minus.jpg";
		this->pictureBox_minus15->Location = System::Drawing::Point(461, 211);
		this->pictureBox_minus15->Name = L"pictureBox_minus15";
		this->pictureBox_minus15->Size = System::Drawing::Size(21, 21);
		this->pictureBox_minus15->TabIndex = 136;
		this->pictureBox_minus15->TabStop = false;
		this->pictureBox_minus15->Click += gcnew System::EventHandler(this, &CreateHero::pictureBox_minus15_Click);
		// 
		// pictureBox_plus15
		// 
		this->pictureBox_plus15->Cursor = System::Windows::Forms::Cursors::Hand;
		this->pictureBox_plus15->ImageLocation = L"C:\\Users\\USER\\Desktop\\Warhamer_UI\\img\\plus.jpg";
		this->pictureBox_plus15->Location = System::Drawing::Point(434, 211);
		this->pictureBox_plus15->Name = L"pictureBox_plus15";
		this->pictureBox_plus15->Size = System::Drawing::Size(21, 21);
		this->pictureBox_plus15->TabIndex = 135;
		this->pictureBox_plus15->TabStop = false;
		this->pictureBox_plus15->Click += gcnew System::EventHandler(this, &CreateHero::pictureBox_plus15_Click);
		// 
		// pictureBox_minus14
		// 
		this->pictureBox_minus14->Cursor = System::Windows::Forms::Cursors::Hand;
		this->pictureBox_minus14->ImageLocation = L"C:\\Users\\USER\\Desktop\\Warhamer_UI\\img\\minus.jpg";
		this->pictureBox_minus14->Location = System::Drawing::Point(410, 211);
		this->pictureBox_minus14->Name = L"pictureBox_minus14";
		this->pictureBox_minus14->Size = System::Drawing::Size(21, 21);
		this->pictureBox_minus14->TabIndex = 134;
		this->pictureBox_minus14->TabStop = false;
		this->pictureBox_minus14->Click += gcnew System::EventHandler(this, &CreateHero::pictureBox_minus14_Click);
		// 
		// pictureBox_plus14
		// 
		this->pictureBox_plus14->Cursor = System::Windows::Forms::Cursors::Hand;
		this->pictureBox_plus14->ImageLocation = L"C:\\Users\\USER\\Desktop\\Warhamer_UI\\img\\plus.jpg";
		this->pictureBox_plus14->Location = System::Drawing::Point(383, 211);
		this->pictureBox_plus14->Name = L"pictureBox_plus14";
		this->pictureBox_plus14->Size = System::Drawing::Size(21, 21);
		this->pictureBox_plus14->TabIndex = 133;
		this->pictureBox_plus14->TabStop = false;
		this->pictureBox_plus14->Click += gcnew System::EventHandler(this, &CreateHero::pictureBox_plus14_Click);
		// 
		// pictureBox_minus13
		// 
		this->pictureBox_minus13->Cursor = System::Windows::Forms::Cursors::Hand;
		this->pictureBox_minus13->ImageLocation = L"C:\\Users\\USER\\Desktop\\Warhamer_UI\\img\\minus.jpg";
		this->pictureBox_minus13->Location = System::Drawing::Point(358, 211);
		this->pictureBox_minus13->Name = L"pictureBox_minus13";
		this->pictureBox_minus13->Size = System::Drawing::Size(21, 21);
		this->pictureBox_minus13->TabIndex = 132;
		this->pictureBox_minus13->TabStop = false;
		this->pictureBox_minus13->Click += gcnew System::EventHandler(this, &CreateHero::pictureBox_minus13_Click);
		// 
		// pictureBox_plus13
		// 
		this->pictureBox_plus13->Cursor = System::Windows::Forms::Cursors::Hand;
		this->pictureBox_plus13->ImageLocation = L"C:\\Users\\USER\\Desktop\\Warhamer_UI\\img\\plus.jpg";
		this->pictureBox_plus13->Location = System::Drawing::Point(331, 211);
		this->pictureBox_plus13->Name = L"pictureBox_plus13";
		this->pictureBox_plus13->Size = System::Drawing::Size(21, 21);
		this->pictureBox_plus13->TabIndex = 131;
		this->pictureBox_plus13->TabStop = false;
		this->pictureBox_plus13->Click += gcnew System::EventHandler(this, &CreateHero::pictureBox_plus13_Click);
		// 
		// pictureBox_minus12
		// 
		this->pictureBox_minus12->Cursor = System::Windows::Forms::Cursors::Hand;
		this->pictureBox_minus12->ImageLocation = L"C:\\Users\\USER\\Desktop\\Warhamer_UI\\img\\minus.jpg";
		this->pictureBox_minus12->Location = System::Drawing::Point(306, 211);
		this->pictureBox_minus12->Name = L"pictureBox_minus12";
		this->pictureBox_minus12->Size = System::Drawing::Size(21, 21);
		this->pictureBox_minus12->TabIndex = 130;
		this->pictureBox_minus12->TabStop = false;
		this->pictureBox_minus12->Click += gcnew System::EventHandler(this, &CreateHero::pictureBox_minus12_Click);
		// 
		// pictureBox_plus12
		// 
		this->pictureBox_plus12->Cursor = System::Windows::Forms::Cursors::Hand;
		this->pictureBox_plus12->ImageLocation = L"C:\\Users\\USER\\Desktop\\Warhamer_UI\\img\\plus.jpg";
		this->pictureBox_plus12->Location = System::Drawing::Point(279, 211);
		this->pictureBox_plus12->Name = L"pictureBox_plus12";
		this->pictureBox_plus12->Size = System::Drawing::Size(21, 21);
		this->pictureBox_plus12->TabIndex = 129;
		this->pictureBox_plus12->TabStop = false;
		this->pictureBox_plus12->Click += gcnew System::EventHandler(this, &CreateHero::pictureBox_plus12_Click);
		// 
		// pictureBox_minus11
		// 
		this->pictureBox_minus11->Cursor = System::Windows::Forms::Cursors::Hand;
		this->pictureBox_minus11->ImageLocation = L"C:\\Users\\USER\\Desktop\\Warhamer_UI\\img\\minus.jpg";
		this->pictureBox_minus11->Location = System::Drawing::Point(255, 211);
		this->pictureBox_minus11->Name = L"pictureBox_minus11";
		this->pictureBox_minus11->Size = System::Drawing::Size(21, 21);
		this->pictureBox_minus11->TabIndex = 128;
		this->pictureBox_minus11->TabStop = false;
		this->pictureBox_minus11->Click += gcnew System::EventHandler(this, &CreateHero::pictureBox_minus11_Click);
		// 
		// pictureBox_plus11
		// 
		this->pictureBox_plus11->Cursor = System::Windows::Forms::Cursors::Hand;
		this->pictureBox_plus11->ImageLocation = L"C:\\Users\\USER\\Desktop\\Warhamer_UI\\img\\plus.jpg";
		this->pictureBox_plus11->Location = System::Drawing::Point(228, 211);
		this->pictureBox_plus11->Name = L"pictureBox_plus11";
		this->pictureBox_plus11->Size = System::Drawing::Size(21, 21);
		this->pictureBox_plus11->TabIndex = 127;
		this->pictureBox_plus11->TabStop = false;
		this->pictureBox_plus11->Click += gcnew System::EventHandler(this, &CreateHero::pictureBox_plus11_Click);
		// 
		// pictureBox_minus10
		// 
		this->pictureBox_minus10->Cursor = System::Windows::Forms::Cursors::Hand;
		this->pictureBox_minus10->ImageLocation = L"C:\\Users\\USER\\Desktop\\Warhamer_UI\\img\\minus.jpg";
		this->pictureBox_minus10->Location = System::Drawing::Point(204, 211);
		this->pictureBox_minus10->Name = L"pictureBox_minus10";
		this->pictureBox_minus10->Size = System::Drawing::Size(21, 21);
		this->pictureBox_minus10->TabIndex = 126;
		this->pictureBox_minus10->TabStop = false;
		this->pictureBox_minus10->Click += gcnew System::EventHandler(this, &CreateHero::pictureBox_minus10_Click);
		// 
		// pictureBox_plus10
		// 
		this->pictureBox_plus10->Cursor = System::Windows::Forms::Cursors::Hand;
		this->pictureBox_plus10->ImageLocation = L"C:\\Users\\USER\\Desktop\\Warhamer_UI\\img\\plus.jpg";
		this->pictureBox_plus10->Location = System::Drawing::Point(177, 211);
		this->pictureBox_plus10->Name = L"pictureBox_plus10";
		this->pictureBox_plus10->Size = System::Drawing::Size(21, 21);
		this->pictureBox_plus10->TabIndex = 125;
		this->pictureBox_plus10->TabStop = false;
		this->pictureBox_plus10->Click += gcnew System::EventHandler(this, &CreateHero::pictureBox_plus10_Click);
		// 
		// pictureBox_minus9
		// 
		this->pictureBox_minus9->Cursor = System::Windows::Forms::Cursors::Hand;
		this->pictureBox_minus9->ImageLocation = L"C:\\Users\\USER\\Desktop\\Warhamer_UI\\img\\minus.jpg";
		this->pictureBox_minus9->Location = System::Drawing::Point(146, 211);
		this->pictureBox_minus9->Name = L"pictureBox_minus9";
		this->pictureBox_minus9->Size = System::Drawing::Size(21, 21);
		this->pictureBox_minus9->TabIndex = 124;
		this->pictureBox_minus9->TabStop = false;
		this->pictureBox_minus9->Click += gcnew System::EventHandler(this, &CreateHero::pictureBox_minus9_Click);
		// 
		// pictureBox_plus9
		// 
		this->pictureBox_plus9->Cursor = System::Windows::Forms::Cursors::Hand;
		this->pictureBox_plus9->ImageLocation = L"C:\\Users\\USER\\Desktop\\Warhamer_UI\\img\\plus.jpg";
		this->pictureBox_plus9->Location = System::Drawing::Point(119, 211);
		this->pictureBox_plus9->Name = L"pictureBox_plus9";
		this->pictureBox_plus9->Size = System::Drawing::Size(21, 21);
		this->pictureBox_plus9->TabIndex = 123;
		this->pictureBox_plus9->TabStop = false;
		this->pictureBox_plus9->Click += gcnew System::EventHandler(this, &CreateHero::pictureBox_plus9_Click);
		// 
		// pictureBox_minus8
		// 
		this->pictureBox_minus8->Cursor = System::Windows::Forms::Cursors::Hand;
		this->pictureBox_minus8->ImageLocation = L"C:\\Users\\USER\\Desktop\\Warhamer_UI\\img\\minus.jpg";
		this->pictureBox_minus8->Location = System::Drawing::Point(515, 101);
		this->pictureBox_minus8->Name = L"pictureBox_minus8";
		this->pictureBox_minus8->Size = System::Drawing::Size(21, 21);
		this->pictureBox_minus8->TabIndex = 122;
		this->pictureBox_minus8->TabStop = false;
		this->pictureBox_minus8->Click += gcnew System::EventHandler(this, &CreateHero::pictureBox_minus8_Click);
		// 
		// pictureBox_plus8
		// 
		this->pictureBox_plus8->Cursor = System::Windows::Forms::Cursors::Hand;
		this->pictureBox_plus8->ImageLocation = L"C:\\Users\\USER\\Desktop\\Warhamer_UI\\img\\plus.jpg";
		this->pictureBox_plus8->Location = System::Drawing::Point(488, 101);
		this->pictureBox_plus8->Name = L"pictureBox_plus8";
		this->pictureBox_plus8->Size = System::Drawing::Size(21, 21);
		this->pictureBox_plus8->TabIndex = 121;
		this->pictureBox_plus8->TabStop = false;
		this->pictureBox_plus8->Click += gcnew System::EventHandler(this, &CreateHero::pictureBox_plus8_Click);
		// 
		// pictureBox_minus7
		// 
		this->pictureBox_minus7->Cursor = System::Windows::Forms::Cursors::Hand;
		this->pictureBox_minus7->ImageLocation = L"C:\\Users\\USER\\Desktop\\Warhamer_UI\\img\\minus.jpg";
		this->pictureBox_minus7->Location = System::Drawing::Point(461, 101);
		this->pictureBox_minus7->Name = L"pictureBox_minus7";
		this->pictureBox_minus7->Size = System::Drawing::Size(21, 21);
		this->pictureBox_minus7->TabIndex = 120;
		this->pictureBox_minus7->TabStop = false;
		this->pictureBox_minus7->Click += gcnew System::EventHandler(this, &CreateHero::pictureBox_minus7_Click);
		// 
		// pictureBox_plus7
		// 
		this->pictureBox_plus7->Cursor = System::Windows::Forms::Cursors::Hand;
		this->pictureBox_plus7->ImageLocation = L"C:\\Users\\USER\\Desktop\\Warhamer_UI\\img\\plus.jpg";
		this->pictureBox_plus7->Location = System::Drawing::Point(434, 101);
		this->pictureBox_plus7->Name = L"pictureBox_plus7";
		this->pictureBox_plus7->Size = System::Drawing::Size(21, 21);
		this->pictureBox_plus7->TabIndex = 119;
		this->pictureBox_plus7->TabStop = false;
		this->pictureBox_plus7->Click += gcnew System::EventHandler(this, &CreateHero::pictureBox_plus7_Click);
		// 
		// pictureBox_minus6
		// 
		this->pictureBox_minus6->Cursor = System::Windows::Forms::Cursors::Hand;
		this->pictureBox_minus6->ImageLocation = L"C:\\Users\\USER\\Desktop\\Warhamer_UI\\img\\minus.jpg";
		this->pictureBox_minus6->Location = System::Drawing::Point(410, 101);
		this->pictureBox_minus6->Name = L"pictureBox_minus6";
		this->pictureBox_minus6->Size = System::Drawing::Size(21, 21);
		this->pictureBox_minus6->TabIndex = 118;
		this->pictureBox_minus6->TabStop = false;
		this->pictureBox_minus6->Click += gcnew System::EventHandler(this, &CreateHero::pictureBox_minus6_Click);
		// 
		// pictureBox_plus6
		// 
		this->pictureBox_plus6->Cursor = System::Windows::Forms::Cursors::Hand;
		this->pictureBox_plus6->ImageLocation = L"C:\\Users\\USER\\Desktop\\Warhamer_UI\\img\\plus.jpg";
		this->pictureBox_plus6->Location = System::Drawing::Point(383, 101);
		this->pictureBox_plus6->Name = L"pictureBox_plus6";
		this->pictureBox_plus6->Size = System::Drawing::Size(21, 21);
		this->pictureBox_plus6->TabIndex = 117;
		this->pictureBox_plus6->TabStop = false;
		this->pictureBox_plus6->Click += gcnew System::EventHandler(this, &CreateHero::pictureBox_plus6_Click);
		// 
		// pictureBox_minus5
		// 
		this->pictureBox_minus5->Cursor = System::Windows::Forms::Cursors::Hand;
		this->pictureBox_minus5->ImageLocation = L"C:\\Users\\USER\\Desktop\\Warhamer_UI\\img\\minus.jpg";
		this->pictureBox_minus5->Location = System::Drawing::Point(358, 101);
		this->pictureBox_minus5->Name = L"pictureBox_minus5";
		this->pictureBox_minus5->Size = System::Drawing::Size(21, 21);
		this->pictureBox_minus5->TabIndex = 116;
		this->pictureBox_minus5->TabStop = false;
		this->pictureBox_minus5->Click += gcnew System::EventHandler(this, &CreateHero::pictureBox_minus5_Click);
		// 
		// pictureBox_plus5
		// 
		this->pictureBox_plus5->Cursor = System::Windows::Forms::Cursors::Hand;
		this->pictureBox_plus5->ImageLocation = L"C:\\Users\\USER\\Desktop\\Warhamer_UI\\img\\plus.jpg";
		this->pictureBox_plus5->Location = System::Drawing::Point(331, 101);
		this->pictureBox_plus5->Name = L"pictureBox_plus5";
		this->pictureBox_plus5->Size = System::Drawing::Size(21, 21);
		this->pictureBox_plus5->TabIndex = 115;
		this->pictureBox_plus5->TabStop = false;
		this->pictureBox_plus5->Click += gcnew System::EventHandler(this, &CreateHero::pictureBox_plus5_Click);
		// 
		// pictureBox_minus4
		// 
		this->pictureBox_minus4->Cursor = System::Windows::Forms::Cursors::Hand;
		this->pictureBox_minus4->ImageLocation = L"C:\\Users\\USER\\Desktop\\Warhamer_UI\\img\\minus.jpg";
		this->pictureBox_minus4->Location = System::Drawing::Point(306, 101);
		this->pictureBox_minus4->Name = L"pictureBox_minus4";
		this->pictureBox_minus4->Size = System::Drawing::Size(21, 21);
		this->pictureBox_minus4->TabIndex = 114;
		this->pictureBox_minus4->TabStop = false;
		this->pictureBox_minus4->Click += gcnew System::EventHandler(this, &CreateHero::pictureBox_minus4_Click);
		// 
		// pictureBox_plus4
		// 
		this->pictureBox_plus4->Cursor = System::Windows::Forms::Cursors::Hand;
		this->pictureBox_plus4->ImageLocation = L"C:\\Users\\USER\\Desktop\\Warhamer_UI\\img\\plus.jpg";
		this->pictureBox_plus4->Location = System::Drawing::Point(279, 101);
		this->pictureBox_plus4->Name = L"pictureBox_plus4";
		this->pictureBox_plus4->Size = System::Drawing::Size(21, 21);
		this->pictureBox_plus4->TabIndex = 113;
		this->pictureBox_plus4->TabStop = false;
		this->pictureBox_plus4->Click += gcnew System::EventHandler(this, &CreateHero::pictureBox_plus4_Click);
		// 
		// pictureBox_minus3
		// 
		this->pictureBox_minus3->Cursor = System::Windows::Forms::Cursors::Hand;
		this->pictureBox_minus3->ImageLocation = L"C:\\Users\\USER\\Desktop\\Warhamer_UI\\img\\minus.jpg";
		this->pictureBox_minus3->Location = System::Drawing::Point(255, 101);
		this->pictureBox_minus3->Name = L"pictureBox_minus3";
		this->pictureBox_minus3->Size = System::Drawing::Size(21, 21);
		this->pictureBox_minus3->TabIndex = 112;
		this->pictureBox_minus3->TabStop = false;
		this->pictureBox_minus3->Click += gcnew System::EventHandler(this, &CreateHero::pictureBox_minus3_Click);
		// 
		// pictureBox_plus3
		// 
		this->pictureBox_plus3->Cursor = System::Windows::Forms::Cursors::Hand;
		this->pictureBox_plus3->ImageLocation = L"C:\\Users\\USER\\Desktop\\Warhamer_UI\\img\\plus.jpg";
		this->pictureBox_plus3->Location = System::Drawing::Point(228, 101);
		this->pictureBox_plus3->Name = L"pictureBox_plus3";
		this->pictureBox_plus3->Size = System::Drawing::Size(21, 21);
		this->pictureBox_plus3->TabIndex = 111;
		this->pictureBox_plus3->TabStop = false;
		this->pictureBox_plus3->Click += gcnew System::EventHandler(this, &CreateHero::pictureBox_plus3_Click);
		// 
		// pictureBox_minus2
		// 
		this->pictureBox_minus2->Cursor = System::Windows::Forms::Cursors::Hand;
		this->pictureBox_minus2->ImageLocation = L"C:\\Users\\USER\\Desktop\\Warhamer_UI\\img\\minus.jpg";
		this->pictureBox_minus2->Location = System::Drawing::Point(204, 101);
		this->pictureBox_minus2->Name = L"pictureBox_minus2";
		this->pictureBox_minus2->Size = System::Drawing::Size(21, 21);
		this->pictureBox_minus2->TabIndex = 110;
		this->pictureBox_minus2->TabStop = false;
		this->pictureBox_minus2->Click += gcnew System::EventHandler(this, &CreateHero::pictureBox_minus2_Click);
		// 
		// pictureBox_plus2
		// 
		this->pictureBox_plus2->Cursor = System::Windows::Forms::Cursors::Hand;
		this->pictureBox_plus2->ImageLocation = L"C:\\Users\\USER\\Desktop\\Warhamer_UI\\img\\plus.jpg";
		this->pictureBox_plus2->Location = System::Drawing::Point(177, 101);
		this->pictureBox_plus2->Name = L"pictureBox_plus2";
		this->pictureBox_plus2->Size = System::Drawing::Size(21, 21);
		this->pictureBox_plus2->TabIndex = 109;
		this->pictureBox_plus2->TabStop = false;
		this->pictureBox_plus2->Click += gcnew System::EventHandler(this, &CreateHero::pictureBox_plus2_Click);
		// 
		// label1
		// 
		this->label1->AutoSize = true;
		this->label1->Font = (gcnew System::Drawing::Font(L"Georgia", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->label1->Location = System::Drawing::Point(3, 215);
		this->label1->Name = L"label1";
		this->label1->Size = System::Drawing::Size(100, 16);
		this->label1->TabIndex = 108;
		this->label1->Text = L"add or occupy:";
		// 
		// sword_ODP
		// 
		this->sword_ODP->Cursor = System::Windows::Forms::Cursors::Hand;
		this->sword_ODP->ImageLocation = L"C:\\Users\\USER\\Desktop\\Warhamer_UI\\img\\sword.jpg";
		this->sword_ODP->Location = System::Drawing::Point(314, 45);
		this->sword_ODP->Name = L"sword_ODP";
		this->sword_ODP->Size = System::Drawing::Size(20, 25);
		this->sword_ODP->TabIndex = 84;
		this->sword_ODP->TabStop = false;
		this->sword_ODP->Click += gcnew System::EventHandler(this, &CreateHero::sword_ODP_Click);
		// 
		// sword_ZR
		// 
		this->sword_ZR->Cursor = System::Windows::Forms::Cursors::Hand;
		this->sword_ZR->ImageLocation = L"C:\\Users\\USER\\Desktop\\Warhamer_UI\\img\\sword.jpg";
		this->sword_ZR->Location = System::Drawing::Point(362, 45);
		this->sword_ZR->Name = L"sword_ZR";
		this->sword_ZR->Size = System::Drawing::Size(20, 25);
		this->sword_ZR->TabIndex = 83;
		this->sword_ZR->TabStop = false;
		this->sword_ZR->Click += gcnew System::EventHandler(this, &CreateHero::sword_ZR_Click);
		// 
		// sword_INT
		// 
		this->sword_INT->Cursor = System::Windows::Forms::Cursors::Hand;
		this->sword_INT->ImageLocation = L"C:\\Users\\USER\\Desktop\\Warhamer_UI\\img\\sword.jpg";
		this->sword_INT->Location = System::Drawing::Point(416, 45);
		this->sword_INT->Name = L"sword_INT";
		this->sword_INT->Size = System::Drawing::Size(20, 25);
		this->sword_INT->TabIndex = 82;
		this->sword_INT->TabStop = false;
		this->sword_INT->Click += gcnew System::EventHandler(this, &CreateHero::sword_INT_Click);
		// 
		// sword_SW
		// 
		this->sword_SW->Cursor = System::Windows::Forms::Cursors::Hand;
		this->sword_SW->ImageLocation = L"C:\\Users\\USER\\Desktop\\Warhamer_UI\\img\\sword.jpg";
		this->sword_SW->Location = System::Drawing::Point(463, 45);
		this->sword_SW->Name = L"sword_SW";
		this->sword_SW->Size = System::Drawing::Size(20, 25);
		this->sword_SW->TabIndex = 81;
		this->sword_SW->TabStop = false;
		this->sword_SW->Click += gcnew System::EventHandler(this, &CreateHero::sword_SW_Click);
		// 
		// sword_OGD
		// 
		this->sword_OGD->Cursor = System::Windows::Forms::Cursors::Hand;
		this->sword_OGD->ImageLocation = L"C:\\Users\\USER\\Desktop\\Warhamer_UI\\img\\sword.jpg";
		this->sword_OGD->Location = System::Drawing::Point(518, 45);
		this->sword_OGD->Name = L"sword_OGD";
		this->sword_OGD->Size = System::Drawing::Size(20, 25);
		this->sword_OGD->TabIndex = 80;
		this->sword_OGD->TabStop = false;
		this->sword_OGD->Click += gcnew System::EventHandler(this, &CreateHero::sword_OGD_Click);
		// 
		// pictureBox_minus1
		// 
		this->pictureBox_minus1->Cursor = System::Windows::Forms::Cursors::Hand;
		this->pictureBox_minus1->ImageLocation = L"C:\\Users\\USER\\Desktop\\Warhamer_UI\\img\\minus.jpg";
		this->pictureBox_minus1->Location = System::Drawing::Point(146, 101);
		this->pictureBox_minus1->Name = L"pictureBox_minus1";
		this->pictureBox_minus1->Size = System::Drawing::Size(21, 21);
		this->pictureBox_minus1->TabIndex = 93;
		this->pictureBox_minus1->TabStop = false;
		this->pictureBox_minus1->Click += gcnew System::EventHandler(this, &CreateHero::pictureBox_minus1_Click);
		// 
		// pictureBox_plus1
		// 
		this->pictureBox_plus1->Cursor = System::Windows::Forms::Cursors::Hand;
		this->pictureBox_plus1->ImageLocation = L"C:\\Users\\USER\\Desktop\\Warhamer_UI\\img\\plus.jpg";
		this->pictureBox_plus1->Location = System::Drawing::Point(119, 101);
		this->pictureBox_plus1->Name = L"pictureBox_plus1";
		this->pictureBox_plus1->Size = System::Drawing::Size(21, 21);
		this->pictureBox_plus1->TabIndex = 85;
		this->pictureBox_plus1->TabStop = false;
		this->pictureBox_plus1->Click += gcnew System::EventHandler(this, &CreateHero::pictureBox_plus1_Click);
		// 
		// sword_K
		// 
		this->sword_K->Cursor = System::Windows::Forms::Cursors::Hand;
		this->sword_K->ImageLocation = L"C:\\Users\\USER\\Desktop\\Warhamer_UI\\img\\sword.jpg";
		this->sword_K->Location = System::Drawing::Point(255, 45);
		this->sword_K->Name = L"sword_K";
		this->sword_K->Size = System::Drawing::Size(20, 25);
		this->sword_K->TabIndex = 79;
		this->sword_K->TabStop = false;
		this->sword_K->Click += gcnew System::EventHandler(this, &CreateHero::sword_K_Click);
		// 
		// sword_US
		// 
		this->sword_US->Cursor = System::Windows::Forms::Cursors::Hand;
		this->sword_US->ImageLocation = L"C:\\Users\\USER\\Desktop\\Warhamer_UI\\img\\sword.jpg";
		this->sword_US->Location = System::Drawing::Point(208, 45);
		this->sword_US->Name = L"sword_US";
		this->sword_US->Size = System::Drawing::Size(20, 25);
		this->sword_US->TabIndex = 78;
		this->sword_US->TabStop = false;
		this->sword_US->Click += gcnew System::EventHandler(this, &CreateHero::sword_US_Click);
		// 
		// textbox_PPc
		// 
		this->textbox_PPc->Enabled = false;
		this->textbox_PPc->Font = (gcnew System::Drawing::Font(L"Georgia", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->textbox_PPc->ForeColor = System::Drawing::Color::Red;
		this->textbox_PPc->Location = System::Drawing::Point(486, 240);
		this->textbox_PPc->Name = L"textbox_PPc";
		this->textbox_PPc->Size = System::Drawing::Size(35, 25);
		this->textbox_PPc->TabIndex = 73;
		// 
		// textbox_POc
		// 
		this->textbox_POc->Enabled = false;
		this->textbox_POc->Font = (gcnew System::Drawing::Font(L"Georgia", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->textbox_POc->ForeColor = System::Drawing::Color::Red;
		this->textbox_POc->Location = System::Drawing::Point(434, 240);
		this->textbox_POc->Name = L"textbox_POc";
		this->textbox_POc->Size = System::Drawing::Size(35, 25);
		this->textbox_POc->TabIndex = 72;
		// 
		// sword_WW
		// 
		this->sword_WW->Cursor = System::Windows::Forms::Cursors::Hand;
		this->sword_WW->ImageLocation = L"C:\\Users\\USER\\Desktop\\Warhamer_UI\\img\\sword.jpg";
		this->sword_WW->Location = System::Drawing::Point(154, 45);
		this->sword_WW->Name = L"sword_WW";
		this->sword_WW->Size = System::Drawing::Size(20, 25);
		this->sword_WW->TabIndex = 77;
		this->sword_WW->TabStop = false;
		this->sword_WW->Click += gcnew System::EventHandler(this, &CreateHero::sword_WW_Click);
		// 
		// textbox_PPa
		// 
		this->textbox_PPa->Font = (gcnew System::Drawing::Font(L"Georgia", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->textbox_PPa->Location = System::Drawing::Point(486, 180);
		this->textbox_PPa->Name = L"textbox_PPa";
		this->textbox_PPa->Size = System::Drawing::Size(35, 25);
		this->textbox_PPa->TabIndex = 69;
		this->textbox_PPa->TextChanged += gcnew System::EventHandler(this, &CreateHero::textbox_PPa_TextChanged);
		// 
		// textbox_POa
		// 
		this->textbox_POa->Font = (gcnew System::Drawing::Font(L"Georgia", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->textbox_POa->Location = System::Drawing::Point(433, 180);
		this->textbox_POa->Name = L"textbox_POa";
		this->textbox_POa->Size = System::Drawing::Size(35, 25);
		this->textbox_POa->TabIndex = 68;
		this->textbox_POa->TextChanged += gcnew System::EventHandler(this, &CreateHero::textbox_POa_TextChanged);
		// 
		// textbox_MAGc
		// 
		this->textbox_MAGc->Enabled = false;
		this->textbox_MAGc->Font = (gcnew System::Drawing::Font(L"Georgia", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->textbox_MAGc->Location = System::Drawing::Point(381, 240);
		this->textbox_MAGc->Name = L"textbox_MAGc";
		this->textbox_MAGc->Size = System::Drawing::Size(35, 25);
		this->textbox_MAGc->TabIndex = 67;
		// 
		// textbox_MAGa
		// 
		this->textbox_MAGa->Font = (gcnew System::Drawing::Font(L"Georgia", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->textbox_MAGa->Location = System::Drawing::Point(381, 180);
		this->textbox_MAGa->Name = L"textbox_MAGa";
		this->textbox_MAGa->Size = System::Drawing::Size(35, 25);
		this->textbox_MAGa->TabIndex = 65;
		this->textbox_MAGa->TextChanged += gcnew System::EventHandler(this, &CreateHero::textbox_MAGa_TextChanged);
		// 
		// textbox_SZc
		// 
		this->textbox_SZc->Enabled = false;
		this->textbox_SZc->Font = (gcnew System::Drawing::Font(L"Georgia", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->textbox_SZc->Location = System::Drawing::Point(331, 240);
		this->textbox_SZc->Name = L"textbox_SZc";
		this->textbox_SZc->Size = System::Drawing::Size(35, 25);
		this->textbox_SZc->TabIndex = 64;
		// 
		// textbox_SZa
		// 
		this->textbox_SZa->Font = (gcnew System::Drawing::Font(L"Georgia", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->textbox_SZa->Location = System::Drawing::Point(331, 180);
		this->textbox_SZa->Name = L"textbox_SZa";
		this->textbox_SZa->Size = System::Drawing::Size(35, 25);
		this->textbox_SZa->TabIndex = 62;
		this->textbox_SZa->TextChanged += gcnew System::EventHandler(this, &CreateHero::textbox_SZa_TextChanged);
		// 
		// textbox_WTc
		// 
		this->textbox_WTc->Enabled = false;
		this->textbox_WTc->Font = (gcnew System::Drawing::Font(L"Georgia", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->textbox_WTc->Location = System::Drawing::Point(279, 240);
		this->textbox_WTc->Name = L"textbox_WTc";
		this->textbox_WTc->Size = System::Drawing::Size(35, 25);
		this->textbox_WTc->TabIndex = 61;
		// 
		// textbox_WTa
		// 
		this->textbox_WTa->Font = (gcnew System::Drawing::Font(L"Georgia", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->textbox_WTa->Location = System::Drawing::Point(279, 180);
		this->textbox_WTa->Name = L"textbox_WTa";
		this->textbox_WTa->Size = System::Drawing::Size(35, 25);
		this->textbox_WTa->TabIndex = 59;
		this->textbox_WTa->TextChanged += gcnew System::EventHandler(this, &CreateHero::textbox_WTa_TextChanged);
		// 
		// textbox_Sc
		// 
		this->textbox_Sc->Enabled = false;
		this->textbox_Sc->Font = (gcnew System::Drawing::Font(L"Georgia", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->textbox_Sc->Location = System::Drawing::Point(226, 240);
		this->textbox_Sc->Name = L"textbox_Sc";
		this->textbox_Sc->Size = System::Drawing::Size(35, 25);
		this->textbox_Sc->TabIndex = 58;
		// 
		// textbox_Sa
		// 
		this->textbox_Sa->Font = (gcnew System::Drawing::Font(L"Georgia", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->textbox_Sa->Location = System::Drawing::Point(226, 180);
		this->textbox_Sa->Name = L"textbox_Sa";
		this->textbox_Sa->Size = System::Drawing::Size(35, 25);
		this->textbox_Sa->TabIndex = 56;
		this->textbox_Sa->TextChanged += gcnew System::EventHandler(this, &CreateHero::textbox_Sa_TextChanged);
		// 
		// textbox_ZYWc
		// 
		this->textbox_ZYWc->Enabled = false;
		this->textbox_ZYWc->Font = (gcnew System::Drawing::Font(L"Georgia", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->textbox_ZYWc->Location = System::Drawing::Point(177, 240);
		this->textbox_ZYWc->Name = L"textbox_ZYWc";
		this->textbox_ZYWc->Size = System::Drawing::Size(35, 25);
		this->textbox_ZYWc->TabIndex = 55;
		// 
		// textbox_Aa
		// 
		this->textbox_Aa->Font = (gcnew System::Drawing::Font(L"Georgia", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->textbox_Aa->Location = System::Drawing::Point(126, 180);
		this->textbox_Aa->Name = L"textbox_Aa";
		this->textbox_Aa->Size = System::Drawing::Size(35, 25);
		this->textbox_Aa->TabIndex = 53;
		this->textbox_Aa->TextChanged += gcnew System::EventHandler(this, &CreateHero::textbox_Aa_TextChanged);
		// 
		// textbox_OGDc
		// 
		this->textbox_OGDc->Enabled = false;
		this->textbox_OGDc->Font = (gcnew System::Drawing::Font(L"Georgia", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->textbox_OGDc->Location = System::Drawing::Point(486, 130);
		this->textbox_OGDc->Name = L"textbox_OGDc";
		this->textbox_OGDc->Size = System::Drawing::Size(35, 25);
		this->textbox_OGDc->TabIndex = 52;
		// 
		// textbox_OGDa
		// 
		this->textbox_OGDa->Font = (gcnew System::Drawing::Font(L"Georgia", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->textbox_OGDa->Location = System::Drawing::Point(486, 70);
		this->textbox_OGDa->Name = L"textbox_OGDa";
		this->textbox_OGDa->Size = System::Drawing::Size(35, 25);
		this->textbox_OGDa->TabIndex = 50;
		this->textbox_OGDa->TextChanged += gcnew System::EventHandler(this, &CreateHero::textbox_OGDa_TextChanged);
		// 
		// textbox_SWc
		// 
		this->textbox_SWc->Enabled = false;
		this->textbox_SWc->Font = (gcnew System::Drawing::Font(L"Georgia", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->textbox_SWc->Location = System::Drawing::Point(433, 130);
		this->textbox_SWc->Name = L"textbox_SWc";
		this->textbox_SWc->Size = System::Drawing::Size(35, 25);
		this->textbox_SWc->TabIndex = 49;
		// 
		// textbox_SWa
		// 
		this->textbox_SWa->Font = (gcnew System::Drawing::Font(L"Georgia", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->textbox_SWa->Location = System::Drawing::Point(433, 70);
		this->textbox_SWa->Name = L"textbox_SWa";
		this->textbox_SWa->Size = System::Drawing::Size(35, 25);
		this->textbox_SWa->TabIndex = 47;
		this->textbox_SWa->TextChanged += gcnew System::EventHandler(this, &CreateHero::textbox_SWa_TextChanged);
		// 
		// textbox_Ac
		// 
		this->textbox_Ac->Enabled = false;
		this->textbox_Ac->Font = (gcnew System::Drawing::Font(L"Georgia", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->textbox_Ac->Location = System::Drawing::Point(126, 240);
		this->textbox_Ac->Name = L"textbox_Ac";
		this->textbox_Ac->Size = System::Drawing::Size(35, 25);
		this->textbox_Ac->TabIndex = 47;
		// 
		// textbox_INTc
		// 
		this->textbox_INTc->Enabled = false;
		this->textbox_INTc->Font = (gcnew System::Drawing::Font(L"Georgia", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->textbox_INTc->Location = System::Drawing::Point(381, 130);
		this->textbox_INTc->Name = L"textbox_INTc";
		this->textbox_INTc->Size = System::Drawing::Size(35, 25);
		this->textbox_INTc->TabIndex = 46;
		// 
		// textbox_INTa
		// 
		this->textbox_INTa->Font = (gcnew System::Drawing::Font(L"Georgia", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->textbox_INTa->Location = System::Drawing::Point(381, 70);
		this->textbox_INTa->Name = L"textbox_INTa";
		this->textbox_INTa->Size = System::Drawing::Size(35, 25);
		this->textbox_INTa->TabIndex = 44;
		this->textbox_INTa->TextChanged += gcnew System::EventHandler(this, &CreateHero::textbox_INTa_TextChanged);
		// 
		// textbox_ZYWa
		// 
		this->textbox_ZYWa->Font = (gcnew System::Drawing::Font(L"Georgia", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->textbox_ZYWa->Location = System::Drawing::Point(177, 180);
		this->textbox_ZYWa->Name = L"textbox_ZYWa";
		this->textbox_ZYWa->Size = System::Drawing::Size(35, 25);
		this->textbox_ZYWa->TabIndex = 44;
		this->textbox_ZYWa->TextChanged += gcnew System::EventHandler(this, &CreateHero::textbox_ZYWa_TextChanged);
		// 
		// textbox_ZRc
		// 
		this->textbox_ZRc->Enabled = false;
		this->textbox_ZRc->Font = (gcnew System::Drawing::Font(L"Georgia", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->textbox_ZRc->Location = System::Drawing::Point(331, 130);
		this->textbox_ZRc->Name = L"textbox_ZRc";
		this->textbox_ZRc->Size = System::Drawing::Size(35, 25);
		this->textbox_ZRc->TabIndex = 43;
		// 
		// textbox_ZRa
		// 
		this->textbox_ZRa->Font = (gcnew System::Drawing::Font(L"Georgia", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->textbox_ZRa->Location = System::Drawing::Point(331, 70);
		this->textbox_ZRa->Name = L"textbox_ZRa";
		this->textbox_ZRa->Size = System::Drawing::Size(35, 25);
		this->textbox_ZRa->TabIndex = 41;
		this->textbox_ZRa->TextChanged += gcnew System::EventHandler(this, &CreateHero::textbox_ZRa_TextChanged);
		// 
		// textbox_ODPc
		// 
		this->textbox_ODPc->Enabled = false;
		this->textbox_ODPc->Font = (gcnew System::Drawing::Font(L"Georgia", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->textbox_ODPc->Location = System::Drawing::Point(279, 130);
		this->textbox_ODPc->Name = L"textbox_ODPc";
		this->textbox_ODPc->Size = System::Drawing::Size(35, 25);
		this->textbox_ODPc->TabIndex = 40;
		// 
		// textbox_ODPa
		// 
		this->textbox_ODPa->Font = (gcnew System::Drawing::Font(L"Georgia", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->textbox_ODPa->Location = System::Drawing::Point(279, 70);
		this->textbox_ODPa->Name = L"textbox_ODPa";
		this->textbox_ODPa->Size = System::Drawing::Size(35, 25);
		this->textbox_ODPa->TabIndex = 38;
		this->textbox_ODPa->TextChanged += gcnew System::EventHandler(this, &CreateHero::textbox_ODPa_TextChanged);
		// 
		// textbox_Kc
		// 
		this->textbox_Kc->Enabled = false;
		this->textbox_Kc->Font = (gcnew System::Drawing::Font(L"Georgia", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->textbox_Kc->Location = System::Drawing::Point(226, 130);
		this->textbox_Kc->Name = L"textbox_Kc";
		this->textbox_Kc->Size = System::Drawing::Size(35, 25);
		this->textbox_Kc->TabIndex = 37;
		// 
		// textbox_Ka
		// 
		this->textbox_Ka->Font = (gcnew System::Drawing::Font(L"Georgia", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->textbox_Ka->Location = System::Drawing::Point(226, 70);
		this->textbox_Ka->Name = L"textbox_Ka";
		this->textbox_Ka->Size = System::Drawing::Size(35, 25);
		this->textbox_Ka->TabIndex = 35;
		this->textbox_Ka->TextChanged += gcnew System::EventHandler(this, &CreateHero::textbox_Ka_TextChanged);
		// 
		// textbox_USc
		// 
		this->textbox_USc->Enabled = false;
		this->textbox_USc->Font = (gcnew System::Drawing::Font(L"Georgia", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->textbox_USc->Location = System::Drawing::Point(179, 131);
		this->textbox_USc->Name = L"textbox_USc";
		this->textbox_USc->Size = System::Drawing::Size(35, 25);
		this->textbox_USc->TabIndex = 34;
		// 
		// textbox_USa
		// 
		this->textbox_USa->Font = (gcnew System::Drawing::Font(L"Georgia", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->textbox_USa->Location = System::Drawing::Point(179, 70);
		this->textbox_USa->Name = L"textbox_USa";
		this->textbox_USa->Size = System::Drawing::Size(35, 25);
		this->textbox_USa->TabIndex = 32;
		this->textbox_USa->TextChanged += gcnew System::EventHandler(this, &CreateHero::textbox_USa_TextChanged);
		// 
		// textbox_WWc
		// 
		this->textbox_WWc->Enabled = false;
		this->textbox_WWc->Font = (gcnew System::Drawing::Font(L"Georgia", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->textbox_WWc->ForeColor = System::Drawing::Color::Black;
		this->textbox_WWc->Location = System::Drawing::Point(126, 130);
		this->textbox_WWc->Name = L"textbox_WWc";
		this->textbox_WWc->Size = System::Drawing::Size(35, 25);
		this->textbox_WWc->TabIndex = 31;
		// 
		// textbox_WWa
		// 
		this->textbox_WWa->Font = (gcnew System::Drawing::Font(L"Georgia", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->textbox_WWa->Location = System::Drawing::Point(126, 70);
		this->textbox_WWa->Name = L"textbox_WWa";
		this->textbox_WWa->Size = System::Drawing::Size(35, 25);
		this->textbox_WWa->TabIndex = 29;
		this->textbox_WWa->TextChanged += gcnew System::EventHandler(this, &CreateHero::textbox_WWa_TextChanged);
		// 
		// label_PP
		// 
		this->label_PP->AutoSize = true;
		this->label_PP->Font = (gcnew System::Drawing::Font(L"Georgia", 7.8F, System::Drawing::FontStyle::Bold));
		this->label_PP->Location = System::Drawing::Point(482, 158);
		this->label_PP->Name = L"label_PP";
		this->label_PP->Size = System::Drawing::Size(25, 16);
		this->label_PP->TabIndex = 28;
		this->label_PP->Text = L"PP";
		// 
		// label_PO
		// 
		this->label_PO->AutoSize = true;
		this->label_PO->Font = (gcnew System::Drawing::Font(L"Georgia", 7.8F, System::Drawing::FontStyle::Bold));
		this->label_PO->Location = System::Drawing::Point(436, 158);
		this->label_PO->Name = L"label_PO";
		this->label_PO->Size = System::Drawing::Size(27, 16);
		this->label_PO->TabIndex = 27;
		this->label_PO->Text = L"PO";
		// 
		// label_MAG
		// 
		this->label_MAG->AutoSize = true;
		this->label_MAG->Font = (gcnew System::Drawing::Font(L"Georgia", 7.8F, System::Drawing::FontStyle::Bold));
		this->label_MAG->Location = System::Drawing::Point(380, 158);
		this->label_MAG->Name = L"label_MAG";
		this->label_MAG->Size = System::Drawing::Size(37, 16);
		this->label_MAG->TabIndex = 26;
		this->label_MAG->Text = L"Mag";
		// 
		// label_SZ
		// 
		this->label_SZ->AutoSize = true;
		this->label_SZ->Font = (gcnew System::Drawing::Font(L"Georgia", 7.8F, System::Drawing::FontStyle::Bold));
		this->label_SZ->Location = System::Drawing::Point(333, 158);
		this->label_SZ->Name = L"label_SZ";
		this->label_SZ->Size = System::Drawing::Size(22, 16);
		this->label_SZ->TabIndex = 25;
		this->label_SZ->Text = L"Sz";
		// 
		// label_WT
		// 
		this->label_WT->AutoSize = true;
		this->label_WT->Font = (gcnew System::Drawing::Font(L"Georgia", 7.8F, System::Drawing::FontStyle::Bold));
		this->label_WT->Location = System::Drawing::Point(280, 158);
		this->label_WT->Name = L"label_WT";
		this->label_WT->Size = System::Drawing::Size(27, 16);
		this->label_WT->TabIndex = 24;
		this->label_WT->Text = L"Wt";
		// 
		// label_S
		// 
		this->label_S->AutoSize = true;
		this->label_S->Font = (gcnew System::Drawing::Font(L"Georgia", 7.8F, System::Drawing::FontStyle::Bold));
		this->label_S->Location = System::Drawing::Point(232, 158);
		this->label_S->Name = L"label_S";
		this->label_S->Size = System::Drawing::Size(15, 16);
		this->label_S->TabIndex = 23;
		this->label_S->Text = L"S";
		// 
		// label_ZYW
		// 
		this->label_ZYW->AutoSize = true;
		this->label_ZYW->Font = (gcnew System::Drawing::Font(L"Georgia", 7.8F, System::Drawing::FontStyle::Bold));
		this->label_ZYW->Location = System::Drawing::Point(176, 158);
		this->label_ZYW->Name = L"label_ZYW";
		this->label_ZYW->Size = System::Drawing::Size(37, 16);
		this->label_ZYW->TabIndex = 22;
		this->label_ZYW->Text = L"Zyw";
		// 
		// label_A
		// 
		this->label_A->AutoSize = true;
		this->label_A->Font = (gcnew System::Drawing::Font(L"Georgia", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->label_A->Location = System::Drawing::Point(128, 158);
		this->label_A->Name = L"label_A";
		this->label_A->Size = System::Drawing::Size(18, 16);
		this->label_A->TabIndex = 21;
		this->label_A->Text = L"A";
		// 
		// label32
		// 
		this->label32->AutoSize = true;
		this->label32->Font = (gcnew System::Drawing::Font(L"Georgia", 7.8F, System::Drawing::FontStyle::Bold));
		this->label32->Location = System::Drawing::Point(276, 46);
		this->label32->Name = L"label32";
		this->label32->Size = System::Drawing::Size(36, 16);
		this->label32->TabIndex = 20;
		this->label32->Text = L"Odp";
		// 
		// label_K
		// 
		this->label_K->AutoSize = true;
		this->label_K->Font = (gcnew System::Drawing::Font(L"Georgia", 7.8F, System::Drawing::FontStyle::Bold));
		this->label_K->Location = System::Drawing::Point(232, 46);
		this->label_K->Name = L"label_K";
		this->label_K->Size = System::Drawing::Size(17, 16);
		this->label_K->TabIndex = 19;
		this->label_K->Text = L"K";
		// 
		// label_SW
		// 
		this->label_SW->AutoSize = true;
		this->label_SW->Font = (gcnew System::Drawing::Font(L"Georgia", 7.8F, System::Drawing::FontStyle::Bold));
		this->label_SW->Location = System::Drawing::Point(436, 46);
		this->label_SW->Name = L"label_SW";
		this->label_SW->Size = System::Drawing::Size(29, 16);
		this->label_SW->TabIndex = 18;
		this->label_SW->Text = L"SW";
		// 
		// label_INT
		// 
		this->label_INT->AutoSize = true;
		this->label_INT->Font = (gcnew System::Drawing::Font(L"Georgia", 7.8F, System::Drawing::FontStyle::Bold));
		this->label_INT->Location = System::Drawing::Point(380, 46);
		this->label_INT->Name = L"label_INT";
		this->label_INT->Size = System::Drawing::Size(30, 16);
		this->label_INT->TabIndex = 17;
		this->label_INT->Text = L"Int";
		// 
		// label_ZR
		// 
		this->label_ZR->AutoSize = true;
		this->label_ZR->Font = (gcnew System::Drawing::Font(L"Georgia", 7.8F, System::Drawing::FontStyle::Bold));
		this->label_ZR->Location = System::Drawing::Point(333, 46);
		this->label_ZR->Name = L"label_ZR";
		this->label_ZR->Size = System::Drawing::Size(23, 16);
		this->label_ZR->TabIndex = 16;
		this->label_ZR->Text = L"Zr";
		// 
		// label_OGD
		// 
		this->label_OGD->AutoSize = true;
		this->label_OGD->Font = (gcnew System::Drawing::Font(L"Georgia", 7.8F, System::Drawing::FontStyle::Bold));
		this->label_OGD->Location = System::Drawing::Point(482, 45);
		this->label_OGD->Name = L"label_OGD";
		this->label_OGD->Size = System::Drawing::Size(35, 16);
		this->label_OGD->TabIndex = 15;
		this->label_OGD->Text = L"Ogd";
		// 
		// label_US
		// 
		this->label_US->AutoSize = true;
		this->label_US->Font = (gcnew System::Drawing::Font(L"Georgia", 7.8F, System::Drawing::FontStyle::Bold));
		this->label_US->Location = System::Drawing::Point(180, 46);
		this->label_US->Name = L"label_US";
		this->label_US->Size = System::Drawing::Size(26, 16);
		this->label_US->TabIndex = 14;
		this->label_US->Text = L"US";
		// 
		// label_WW
		// 
		this->label_WW->AutoSize = true;
		this->label_WW->Font = (gcnew System::Drawing::Font(L"Georgia", 7.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->label_WW->Location = System::Drawing::Point(121, 46);
		this->label_WW->Name = L"label_WW";
		this->label_WW->Size = System::Drawing::Size(35, 15);
		this->label_WW->TabIndex = 13;
		this->label_WW->Text = L"WW";
		// 
		// label_current2
		// 
		this->label_current2->AutoSize = true;
		this->label_current2->Font = (gcnew System::Drawing::Font(L"Georgia", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->label_current2->Location = System::Drawing::Point(3, 245);
		this->label_current2->Name = L"label_current2";
		this->label_current2->Size = System::Drawing::Size(54, 16);
		this->label_current2->TabIndex = 12;
		this->label_current2->Text = L"current";
		// 
		// label_initial2
		// 
		this->label_initial2->AutoSize = true;
		this->label_initial2->Font = (gcnew System::Drawing::Font(L"Georgia", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->label_initial2->Location = System::Drawing::Point(2, 185);
		this->label_initial2->Name = L"label_initial2";
		this->label_initial2->Size = System::Drawing::Size(47, 16);
		this->label_initial2->TabIndex = 10;
		this->label_initial2->Text = L"initial:";
		// 
		// label_secondary
		// 
		this->label_secondary->AutoSize = true;
		this->label_secondary->Font = (gcnew System::Drawing::Font(L"Georgia", 7.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->label_secondary->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)),
			static_cast<System::Int32>(static_cast<System::Byte>(25)));
		this->label_secondary->Location = System::Drawing::Point(3, 160);
		this->label_secondary->Name = L"label_secondary";
		this->label_secondary->Size = System::Drawing::Size(79, 15);
		this->label_secondary->TabIndex = 9;
		this->label_secondary->Text = L"Secondary:";
		// 
		// label_current1
		// 
		this->label_current1->AutoSize = true;
		this->label_current1->Font = (gcnew System::Drawing::Font(L"Georgia", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->label_current1->Location = System::Drawing::Point(3, 130);
		this->label_current1->Name = L"label_current1";
		this->label_current1->Size = System::Drawing::Size(58, 16);
		this->label_current1->TabIndex = 8;
		this->label_current1->Text = L"current:";
		// 
		// label_development1
		// 
		this->label_development1->AutoSize = true;
		this->label_development1->Font = (gcnew System::Drawing::Font(L"Georgia", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->label_development1->Location = System::Drawing::Point(2, 106);
		this->label_development1->Name = L"label_development1";
		this->label_development1->Size = System::Drawing::Size(100, 16);
		this->label_development1->TabIndex = 7;
		this->label_development1->Text = L"add or occupy:";
		// 
		// label_initial1
		// 
		this->label_initial1->AutoSize = true;
		this->label_initial1->Font = (gcnew System::Drawing::Font(L"Georgia", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->label_initial1->Location = System::Drawing::Point(4, 75);
		this->label_initial1->Name = L"label_initial1";
		this->label_initial1->Size = System::Drawing::Size(47, 16);
		this->label_initial1->TabIndex = 6;
		this->label_initial1->Text = L"initial:";
		// 
		// label_featuresmain
		// 
		this->label_featuresmain->AutoSize = true;
		this->label_featuresmain->Font = (gcnew System::Drawing::Font(L"Georgia", 7.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->label_featuresmain->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)),
			static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)));
		this->label_featuresmain->Location = System::Drawing::Point(4, 45);
		this->label_featuresmain->Name = L"label_featuresmain";
		this->label_featuresmain->Size = System::Drawing::Size(106, 15);
		this->label_featuresmain->TabIndex = 5;
		this->label_featuresmain->Text = L"Main Features:";
		// 
		// panel_features
		// 
		this->panel_features->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
			| System::Windows::Forms::AnchorStyles::Right));
		this->panel_features->BackColor = System::Drawing::Color::Black;
		this->panel_features->Controls->Add(this->features_label);
		this->panel_features->Controls->Add(this->pictureBox16);
		this->panel_features->Location = System::Drawing::Point(0, 1);
		this->panel_features->Name = L"panel_features";
		this->panel_features->Size = System::Drawing::Size(542, 41);
		this->panel_features->TabIndex = 0;
		// 
		// features_label
		// 
		this->features_label->AutoSize = true;
		this->features_label->BackColor = System::Drawing::Color::Black;
		this->features_label->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		this->features_label->Font = (gcnew System::Drawing::Font(L"Georgia", 20, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
		this->features_label->ForeColor = System::Drawing::Color::White;
		this->features_label->Location = System::Drawing::Point(153, 2);
		this->features_label->Name = L"features_label";
		this->features_label->Size = System::Drawing::Size(216, 39);
		this->features_label->TabIndex = 4;
		this->features_label->Text = L"FEATURES";
		// 
		// pictureBox16
		// 
		this->pictureBox16->Location = System::Drawing::Point(0, 0);
		this->pictureBox16->Name = L"pictureBox16";
		this->pictureBox16->Size = System::Drawing::Size(100, 50);
		this->pictureBox16->TabIndex = 5;
		this->pictureBox16->TabStop = false;
		// 
		// manu_creator
		// 
		this->manu_creator->BackColor = System::Drawing::Color::Black;
		this->manu_creator->ImageScalingSize = System::Drawing::Size(20, 20);
		this->manu_creator->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
			this->menuToolStripMenuItem,
				this->heroOptionsToolStripMenuItem, this->heroDescriptionToolStripMenuItem, this->featuresToolStripMenuItem, this->armorPointsToolStripMenuItem
		});
		this->manu_creator->Location = System::Drawing::Point(0, 0);
		this->manu_creator->Name = L"manu_creator";
		this->manu_creator->Size = System::Drawing::Size(1138, 28);
		this->manu_creator->TabIndex = 18;
		this->manu_creator->Text = L"menuStrip1";
		// 
		// menuToolStripMenuItem
		// 
		this->menuToolStripMenuItem->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)),
			static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)));
		this->menuToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
			this->choseFileToolStripMenuItem,
				this->randomAllToolStripMenuItem, this->openToolStripMenuItem, this->saveAllToolStripMenuItem, this->clearAllToolStripMenuItem,
				this->closeFormToolStripMenuItem
		});
		this->menuToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->menuToolStripMenuItem->ForeColor = System::Drawing::Color::White;
		this->menuToolStripMenuItem->Name = L"menuToolStripMenuItem";
		this->menuToolStripMenuItem->Size = System::Drawing::Size(60, 24);
		this->menuToolStripMenuItem->Text = L"Menu";
		// 
		// choseFileToolStripMenuItem
		// 
		this->choseFileToolStripMenuItem->BackColor = System::Drawing::Color::Black;
		this->choseFileToolStripMenuItem->ForeColor = System::Drawing::Color::White;
		this->choseFileToolStripMenuItem->Name = L"choseFileToolStripMenuItem";
		this->choseFileToolStripMenuItem->Size = System::Drawing::Size(224, 26);
		this->choseFileToolStripMenuItem->Text = L"Choose File";
		this->choseFileToolStripMenuItem->Click += gcnew System::EventHandler(this, &CreateHero::choseFileToolStripMenuItem_Click);
		// 
		// randomAllToolStripMenuItem
		// 
		this->randomAllToolStripMenuItem->BackColor = System::Drawing::Color::Black;
		this->randomAllToolStripMenuItem->ForeColor = System::Drawing::Color::White;
		this->randomAllToolStripMenuItem->Name = L"randomAllToolStripMenuItem";
		this->randomAllToolStripMenuItem->Size = System::Drawing::Size(224, 26);
		this->randomAllToolStripMenuItem->Text = L"Random Base";
		this->randomAllToolStripMenuItem->Click += gcnew System::EventHandler(this, &CreateHero::randomAllToolStripMenuItem_Click);
		// 
		// saveAllToolStripMenuItem
		// 
		this->saveAllToolStripMenuItem->BackColor = System::Drawing::Color::Black;
		this->saveAllToolStripMenuItem->ForeColor = System::Drawing::Color::White;
		this->saveAllToolStripMenuItem->Name = L"saveAllToolStripMenuItem";
		this->saveAllToolStripMenuItem->Size = System::Drawing::Size(224, 26);
		this->saveAllToolStripMenuItem->Text = L"Save Hero";
		this->saveAllToolStripMenuItem->Click += gcnew System::EventHandler(this, &CreateHero::saveAllToolStripMenuItem_Click);
		// 
		// clearAllToolStripMenuItem
		// 
		this->clearAllToolStripMenuItem->BackColor = System::Drawing::Color::Black;
		this->clearAllToolStripMenuItem->ForeColor = System::Drawing::Color::White;
		this->clearAllToolStripMenuItem->Name = L"clearAllToolStripMenuItem";
		this->clearAllToolStripMenuItem->Size = System::Drawing::Size(224, 26);
		this->clearAllToolStripMenuItem->Text = L"Clear ";
		this->clearAllToolStripMenuItem->Click += gcnew System::EventHandler(this, &CreateHero::clearAllToolStripMenuItem_Click);
		// 
		// closeFormToolStripMenuItem
		// 
		this->closeFormToolStripMenuItem->BackColor = System::Drawing::Color::Black;
		this->closeFormToolStripMenuItem->ForeColor = System::Drawing::Color::White;
		this->closeFormToolStripMenuItem->Name = L"closeFormToolStripMenuItem";
		this->closeFormToolStripMenuItem->Size = System::Drawing::Size(224, 26);
		this->closeFormToolStripMenuItem->Text = L"Close form";
		this->closeFormToolStripMenuItem->Click += gcnew System::EventHandler(this, &CreateHero::closeFormToolStripMenuItem_Click);
		// 
		// heroOptionsToolStripMenuItem
		// 
		this->heroOptionsToolStripMenuItem->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)),
			static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)));
		this->heroOptionsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
			this->saveToolStripMenuItem,
				this->clearToolStripMenuItem, this->randomToolStripMenuItem
		});
		this->heroOptionsToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->heroOptionsToolStripMenuItem->ForeColor = System::Drawing::Color::White;
		this->heroOptionsToolStripMenuItem->Name = L"heroOptionsToolStripMenuItem";
		this->heroOptionsToolStripMenuItem->Size = System::Drawing::Size(112, 24);
		this->heroOptionsToolStripMenuItem->Text = L"Hero Options";
		// 
		// saveToolStripMenuItem
		// 
		this->saveToolStripMenuItem->BackColor = System::Drawing::Color::Black;
		this->saveToolStripMenuItem->ForeColor = System::Drawing::Color::White;
		this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
		this->saveToolStripMenuItem->Size = System::Drawing::Size(148, 26);
		this->saveToolStripMenuItem->Text = L"Save";
		this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &CreateHero::saveToolStripMenuItem_Click);
		// 
		// clearToolStripMenuItem
		// 
		this->clearToolStripMenuItem->BackColor = System::Drawing::Color::Black;
		this->clearToolStripMenuItem->ForeColor = System::Drawing::Color::White;
		this->clearToolStripMenuItem->Name = L"clearToolStripMenuItem";
		this->clearToolStripMenuItem->Size = System::Drawing::Size(148, 26);
		this->clearToolStripMenuItem->Text = L"Clear";
		this->clearToolStripMenuItem->Click += gcnew System::EventHandler(this, &CreateHero::clearToolStripMenuItem_Click);
		// 
		// randomToolStripMenuItem
		// 
		this->randomToolStripMenuItem->BackColor = System::Drawing::Color::Black;
		this->randomToolStripMenuItem->ForeColor = System::Drawing::Color::White;
		this->randomToolStripMenuItem->Name = L"randomToolStripMenuItem";
		this->randomToolStripMenuItem->Size = System::Drawing::Size(148, 26);
		this->randomToolStripMenuItem->Text = L"Random";
		this->randomToolStripMenuItem->Click += gcnew System::EventHandler(this, &CreateHero::randomToolStripMenuItem_Click);
		// 
		// heroDescriptionToolStripMenuItem
		// 
		this->heroDescriptionToolStripMenuItem->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)),
			static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)));
		this->heroDescriptionToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
			this->saveToolStripMenuItem1,
				this->clearToolStripMenuItem1, this->randomStatsToolStripMenuItem
		});
		this->heroDescriptionToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular,
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
		this->heroDescriptionToolStripMenuItem->ForeColor = System::Drawing::Color::White;
		this->heroDescriptionToolStripMenuItem->Name = L"heroDescriptionToolStripMenuItem";
		this->heroDescriptionToolStripMenuItem->Size = System::Drawing::Size(136, 24);
		this->heroDescriptionToolStripMenuItem->Text = L"Hero Description";
		// 
		// saveToolStripMenuItem1
		// 
		this->saveToolStripMenuItem1->BackColor = System::Drawing::Color::Black;
		this->saveToolStripMenuItem1->ForeColor = System::Drawing::Color::White;
		this->saveToolStripMenuItem1->Name = L"saveToolStripMenuItem1";
		this->saveToolStripMenuItem1->Size = System::Drawing::Size(152, 26);
		this->saveToolStripMenuItem1->Text = L"Save";
		this->saveToolStripMenuItem1->Click += gcnew System::EventHandler(this, &CreateHero::saveToolStripMenuItem1_Click);
		// 
		// clearToolStripMenuItem1
		// 
		this->clearToolStripMenuItem1->BackColor = System::Drawing::Color::Black;
		this->clearToolStripMenuItem1->ForeColor = System::Drawing::Color::White;
		this->clearToolStripMenuItem1->Name = L"clearToolStripMenuItem1";
		this->clearToolStripMenuItem1->Size = System::Drawing::Size(152, 26);
		this->clearToolStripMenuItem1->Text = L"Clear";
		this->clearToolStripMenuItem1->Click += gcnew System::EventHandler(this, &CreateHero::clearToolStripMenuItem1_Click);
		// 
		// randomStatsToolStripMenuItem
		// 
		this->randomStatsToolStripMenuItem->BackColor = System::Drawing::Color::Black;
		this->randomStatsToolStripMenuItem->ForeColor = System::Drawing::Color::White;
		this->randomStatsToolStripMenuItem->Name = L"randomStatsToolStripMenuItem";
		this->randomStatsToolStripMenuItem->Size = System::Drawing::Size(152, 26);
		this->randomStatsToolStripMenuItem->Text = L"Random ";
		this->randomStatsToolStripMenuItem->Click += gcnew System::EventHandler(this, &CreateHero::randomStatsToolStripMenuItem_Click);
		// 
		// featuresToolStripMenuItem
		// 
		this->featuresToolStripMenuItem->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)),
			static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)));
		this->featuresToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
			this->saveToolStripMenuItem2,
				this->clearToolStripMenuItem2, this->randomToolStripMenuItem1
		});
		this->featuresToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->featuresToolStripMenuItem->ForeColor = System::Drawing::Color::White;
		this->featuresToolStripMenuItem->Name = L"featuresToolStripMenuItem";
		this->featuresToolStripMenuItem->Size = System::Drawing::Size(78, 24);
		this->featuresToolStripMenuItem->Text = L"Features";
		// 
		// saveToolStripMenuItem2
		// 
		this->saveToolStripMenuItem2->BackColor = System::Drawing::Color::Black;
		this->saveToolStripMenuItem2->ForeColor = System::Drawing::Color::White;
		this->saveToolStripMenuItem2->Name = L"saveToolStripMenuItem2";
		this->saveToolStripMenuItem2->Size = System::Drawing::Size(148, 26);
		this->saveToolStripMenuItem2->Text = L"Save";
		this->saveToolStripMenuItem2->Click += gcnew System::EventHandler(this, &CreateHero::saveToolStripMenuItem2_Click);
		// 
		// clearToolStripMenuItem2
		// 
		this->clearToolStripMenuItem2->BackColor = System::Drawing::Color::Black;
		this->clearToolStripMenuItem2->ForeColor = System::Drawing::Color::White;
		this->clearToolStripMenuItem2->Name = L"clearToolStripMenuItem2";
		this->clearToolStripMenuItem2->Size = System::Drawing::Size(148, 26);
		this->clearToolStripMenuItem2->Text = L"Clear";
		this->clearToolStripMenuItem2->Click += gcnew System::EventHandler(this, &CreateHero::clearToolStripMenuItem2_Click);
		// 
		// randomToolStripMenuItem1
		// 
		this->randomToolStripMenuItem1->BackColor = System::Drawing::Color::Black;
		this->randomToolStripMenuItem1->ForeColor = System::Drawing::Color::White;
		this->randomToolStripMenuItem1->Name = L"randomToolStripMenuItem1";
		this->randomToolStripMenuItem1->Size = System::Drawing::Size(148, 26);
		this->randomToolStripMenuItem1->Text = L"Random";
		this->randomToolStripMenuItem1->Click += gcnew System::EventHandler(this, &CreateHero::randomToolStripMenuItem1_Click);
		// 
		// armorPointsToolStripMenuItem
		// 
		this->armorPointsToolStripMenuItem->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)),
			static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)));
		this->armorPointsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
			this->saveToolStripMenuItem3,
				this->clearToolStripMenuItem3, this->randomStatsToolStripMenuItem1
		});
		this->armorPointsToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->armorPointsToolStripMenuItem->ForeColor = System::Drawing::Color::White;
		this->armorPointsToolStripMenuItem->Name = L"armorPointsToolStripMenuItem";
		this->armorPointsToolStripMenuItem->Size = System::Drawing::Size(108, 24);
		this->armorPointsToolStripMenuItem->Text = L"Armor Points";
		// 
		// saveToolStripMenuItem3
		// 
		this->saveToolStripMenuItem3->BackColor = System::Drawing::Color::Black;
		this->saveToolStripMenuItem3->ForeColor = System::Drawing::Color::White;
		this->saveToolStripMenuItem3->Name = L"saveToolStripMenuItem3";
		this->saveToolStripMenuItem3->Size = System::Drawing::Size(148, 26);
		this->saveToolStripMenuItem3->Text = L"Save";
		this->saveToolStripMenuItem3->Click += gcnew System::EventHandler(this, &CreateHero::saveToolStripMenuItem3_Click);
		// 
		// clearToolStripMenuItem3
		// 
		this->clearToolStripMenuItem3->BackColor = System::Drawing::Color::Black;
		this->clearToolStripMenuItem3->ForeColor = System::Drawing::Color::White;
		this->clearToolStripMenuItem3->Name = L"clearToolStripMenuItem3";
		this->clearToolStripMenuItem3->Size = System::Drawing::Size(148, 26);
		this->clearToolStripMenuItem3->Text = L"Clear";
		this->clearToolStripMenuItem3->Click += gcnew System::EventHandler(this, &CreateHero::clearToolStripMenuItem3_Click);
		// 
		// randomStatsToolStripMenuItem1
		// 
		this->randomStatsToolStripMenuItem1->BackColor = System::Drawing::Color::Black;
		this->randomStatsToolStripMenuItem1->ForeColor = System::Drawing::Color::White;
		this->randomStatsToolStripMenuItem1->Name = L"randomStatsToolStripMenuItem1";
		this->randomStatsToolStripMenuItem1->Size = System::Drawing::Size(148, 26);
		this->randomStatsToolStripMenuItem1->Text = L"Random";
		this->randomStatsToolStripMenuItem1->Click += gcnew System::EventHandler(this, &CreateHero::randomStatsToolStripMenuItem1_Click);
		// 
		// openToolStripMenuItem
		// 
		this->openToolStripMenuItem->BackColor = System::Drawing::Color::Black;
		this->openToolStripMenuItem->ForeColor = System::Drawing::Color::White;
		this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
		this->openToolStripMenuItem->Size = System::Drawing::Size(224, 26);
		this->openToolStripMenuItem->Text = L"Open Hero ";
		this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &CreateHero::openToolStripMenuItem_Click);
		// 
		// CreateHero
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->ClientSize = System::Drawing::Size(1138, 1055);
		this->Controls->Add(this->manu_creator);
		this->Controls->Add(this->panel_hero_img);
		this->Controls->Add(this->panel_images);
		this->Controls->Add(this->panel_hero1);
		this->Controls->Add(this->panel_herodesc);
		this->Controls->Add(this->panel_feat);
		this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
		this->MainMenuStrip = this->manu_creator;
		this->MaximizeBox = false;
		this->MinimizeBox = false;
		this->Name = L"CreateHero";
		this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
		this->Text = L"CreateHero";
		this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &CreateHero::CreateHero_MouseDown);
		this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &CreateHero::CreateHero_MouseMove);
		this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &CreateHero::CreateHero_MouseUp);
		this->panel_hero1->ResumeLayout(false);
		this->panel_hero1->PerformLayout();
		this->panel2->ResumeLayout(false);
		this->panel2->PerformLayout();
		this->panel_herodesc->ResumeLayout(false);
		this->panel_herodesc->PerformLayout();
		this->panel_hero_description->ResumeLayout(false);
		this->panel_hero_description->PerformLayout();
		this->panel_images->ResumeLayout(false);
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->welcome_pb))->EndInit();
		this->panel_hero_img->ResumeLayout(false);
		this->panel_hero_img->PerformLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->hero_pb))->EndInit();
		this->panel_feat->ResumeLayout(false);
		this->panel_feat->PerformLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_minus16))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_plus16))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_minus15))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_plus15))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_minus14))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_plus14))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_minus13))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_plus13))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_minus12))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_plus12))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_minus11))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_plus11))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_minus10))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_plus10))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_minus9))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_plus9))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_minus8))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_plus8))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_minus7))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_plus7))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_minus6))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_plus6))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_minus5))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_plus5))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_minus4))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_plus4))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_minus3))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_plus3))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_minus2))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_plus2))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sword_ODP))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sword_ZR))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sword_INT))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sword_SW))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sword_OGD))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_minus1))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_plus1))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sword_K))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sword_US))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sword_WW))->EndInit();
		this->panel_features->ResumeLayout(false);
		this->panel_features->PerformLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox16))->EndInit();
		this->manu_creator->ResumeLayout(false);
		this->manu_creator->PerformLayout();
		this->ResumeLayout(false);
		this->PerformLayout();

	}
	
	Void CreateHero::CreateHero_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		//disable draging
		dragging = false;
	}
		   //varibale to move form using mouse
		   Void CreateHero::hero_pb_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	dragging2 = true;
	offset2.X = e->X;
	offset2.Y = e->Y;
}
		   Void CreateHero::hero_pb_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	//if draging enebled get current mouse pos
	if (dragging2)
	{
		Point mouseposition2 = PointToScreen(Point(e->X, e->Y));
		Location = Point(mouseposition2.X - offset2.X, mouseposition2.Y - offset2.Y);
	}
}
		   Void CreateHero::hero_pb_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	dragging2 = false;
}
	   //MENU OPTIONS
			  //clear all
		   Void CreateHero::clearAllToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	textbox_name->Text = "";
	textbox_race->Text = "";
	textbox_cur_prof->Text = "";
	textbox_prev_prof->Text = "";
	//hero desc
	textbox_age->Text = "";
	textbox_weight->Text = "";
	textbox_height->Text = "";
	textbox_sex->Text = "";
	textbox_star_sign->Text = "";
	textbox_birthplace->Text = "";
	textbox_siblings->Text = "";
	//hero features
	textbox_WWa->Text = "";
	textbox_WWc->Text = "";
	textbox_USa->Text = "";
	textbox_USc->Text = "";
	textbox_Ka->Text = "";
	textbox_Kc->Text = "";
	textbox_ODPa->Text = "";
	textbox_ODPc->Text = "";
	textbox_ZRa->Text = "";
	textbox_ZRc->Text = "";
	textbox_INTa->Text = "";
	textbox_INTc->Text = "";
	textbox_SWa->Text = "";
	textbox_SWc->Text = "";
	textbox_OGDa->Text = "";
	textbox_OGDc->Text = "";
	//secondary features
	textbox_Aa->Text = "";
	textbox_Ac->Text = "";
	textbox_ZYWa->Text = "";
	textbox_ZYWc->Text = "";
	textbox_Sa->Text = "";
	textbox_Sc->Text = "";
	textbox_WTa->Text = "";
	textbox_WTc->Text = "";
	textbox_SZa->Text = "";
	textbox_SZc->Text = "";
	textbox_MAGa->Text = "";
	textbox_MAGc->Text = "";
	textbox_POa->Text = "";
	textbox_POc->Text = "";
	textbox_PPa->Text = "";
	textbox_PPc->Text = "";
	//clear armor points
	tb_headarmor->Text = "";
	tb_bodyarmor->Text = "";
	tb_leftfootarrmor->Text = "";
	tb_rightfarmor->Text = "";
	tb_lefthandarmor->Text = "";
	tb_rhandarmor->Text = "";
}

	   //close form and ask user about saving cart
		   Void CreateHero::closeFormToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	System::Windows::Forms::DialogResult result = MessageBox::Show("Do you want to save changes before closing ?", "Save Changes",
		MessageBoxButtons::YesNoCancel, MessageBoxIcon::Question);
	if (result == System::Windows::Forms::DialogResult::Yes)
	{
		saveAllToolStripMenuItem->PerformClick();
		CreateHero::Close();
	}
	else if (result == System::Windows::Forms::DialogResult::No)
	{
		CreateHero::Close();
	}
}
	   //clear hero
		   Void CreateHero::clearToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	textbox_name->Text = "";
	textbox_race->Text = "";
	textbox_cur_prof->Text = "";
	textbox_prev_prof->Text = "";
}
	   //clear hero desc
		   Void CreateHero::clearToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
	textbox_age->Text = "";
	textbox_weight->Text = "";
	textbox_height->Text = "";
	textbox_sex->Text = "";
	textbox_star_sign->Text = "";
	textbox_birthplace->Text = "";
	textbox_siblings->Text = "";
}
	   //clear features
		   Void CreateHero::clearToolStripMenuItem2_Click(System::Object^ sender, System::EventArgs^ e) {
	textbox_WWa->Text = "";
	textbox_WWc->Text = "";
	textbox_USa->Text = "";
	textbox_USc->Text = "";
	textbox_Ka->Text = "";
	textbox_Kc->Text = "";
	textbox_ODPa->Text = "";
	textbox_ODPc->Text = "";
	textbox_ZRa->Text = "";
	textbox_ZRc->Text = "";
	textbox_INTa->Text = "";
	textbox_INTc->Text = "";
	textbox_SWa->Text = "";
	textbox_SWc->Text = "";
	textbox_OGDa->Text = "";
	textbox_OGDc->Text = "";
	//secondary features
	textbox_Aa->Text = "";
	textbox_Ac->Text = "";
	textbox_ZYWa->Text = "";
	textbox_ZYWc->Text = "";
	textbox_Sa->Text = "";
	textbox_Sc->Text = "";
	textbox_WTa->Text = "";
	textbox_WTc->Text = "";
	textbox_SZa->Text = "";
	textbox_SZc->Text = "";
	textbox_MAGa->Text = "";
	textbox_MAGc->Text = "";
	textbox_POa->Text = "";
	textbox_POc->Text = "";
	textbox_PPa->Text = "";
	textbox_PPc->Text = "";
}
	   //clear armor points
		   Void CreateHero::clearToolStripMenuItem3_Click(System::Object^ sender, System::EventArgs^ e) {
	tb_headarmor->Text = "";
	tb_bodyarmor->Text = "";
	tb_leftfootarrmor->Text = "";
	tb_rightfarmor->Text = "";
	tb_lefthandarmor->Text = "";
	tb_rhandarmor->Text = "";
}
	   //boolen to make aproprite space betwen stats 
	   bool method;
			  Void CreateHero::choseFileToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ file_path;

		try
		{
			OpenFileDialog^ file_dialog = gcnew OpenFileDialog();
			file_dialog->Filter = "Text Files (*.txt)|*.txt|All Files (*.*)|*.*";
			file_dialog->Title = "Choose a file";

			System::Windows::Forms::DialogResult result = file_dialog->ShowDialog();

			if (result == System::Windows::Forms::DialogResult::OK)
			{
				file_path = file_dialog->FileName;
				file_writer = gcnew System::IO::StreamWriter(file_path, true);
			}
		}
		catch (Exception^ er)
		{
			MessageBox::Show(er->Message, "ERROR", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
		  //variable adding difrent prefix depending from line
		  int counter = 1;

		  //method saving to file
		  void CreateHero::save_text_tofile(String^ text)
		  {
			  method = true;
			  try
			  {
				  if (file_writer == nullptr) {
					  OpenFileDialog^ file_dialog = gcnew OpenFileDialog();
					  file_dialog->Filter = "Text Files (*.txt)|*.txt|All Files (*.*)|*.*";
					  file_dialog->Title = "Choose a file";

					  System::Windows::Forms::DialogResult result = file_dialog->ShowDialog();

					  if (result == System::Windows::Forms::DialogResult::OK) {
						  String^ file_path = file_dialog->FileName;
						  file_writer = gcnew System::IO::StreamWriter(file_path, true);
					  }
					  else {
						  return;
					  }
				  }
				  if (file_writer != nullptr) {
					  switch (counter)
					  {
					  case 1:
						  file_writer->WriteLine("Name:" + text);
						  counter++;
						  break;
					  case 2:
						  file_writer->WriteLine("Race: " + text);
						  counter++;
						  break;
					  case 3:
						  file_writer->WriteLine("Current Profession: " + text);
						  counter++;
						  break;
					  case 4:
						  file_writer->WriteLine("Previous Profession: " + text);
						  file_writer->WriteLine("==================================");
						  file_writer->WriteLine("==================================");
						  counter++;
						  break;
					  case 5:
						  file_writer->WriteLine("Age: " + text);
						  counter++;
						  break;
					  case 6:
						  file_writer->WriteLine("Sex: " + text);
						  counter++;
						  break;
					  case 7:
						  file_writer->WriteLine("Height: " + text);
						  counter++;
						  break;
					  case 8:
						  file_writer->WriteLine("Weight: " + text);
						  counter++;
						  break;
					  case 9:
						  file_writer->WriteLine("Star Sign: " + text);
						  counter++;
						  break;
					  case 10:
						  file_writer->WriteLine("Siblings: " + text);
						  counter++;
						  break;
					  case 11:
						  file_writer->WriteLine("Place of Birth: " + text);
						  if (method)file_writer->WriteLine("==================================");
						  if (method)file_writer->WriteLine("==================================");
						  counter++;
						  break;
					  case 12:
						  file_writer->WriteLine("Initial WW: " + text);
						  counter++;
						  break;

					  case 13:
						  file_writer->WriteLine("Current WW: " + text);
						  file_writer->WriteLine("-----------------------------");
						  counter++;
						  break;
					  case 14:
						  file_writer->WriteLine("Initial US: " + text);
						  counter++;
						  break;

					  case 15:
						  file_writer->WriteLine("Current US: " + text);
						  file_writer->WriteLine("-----------------------------");
						  counter++;
						  break;
					  case 16:
						  file_writer->WriteLine("Initial K: " + text);
						  counter++;
						  break;

					  case 17:
						  file_writer->WriteLine("Current K: " + text);
						  file_writer->WriteLine("-----------------------------");
						  counter++;
						  break;
					  case 18:
						  file_writer->WriteLine("Initial Odp: " + text);
						  counter++;
						  break;

					  case 19:
						  file_writer->WriteLine("Current Odp: " + text);
						  file_writer->WriteLine("-----------------------------");
						  counter++;
						  break;
					  case 20:
						  file_writer->WriteLine("Initial Zr: " + text);
						  counter++;
						  break;

					  case 21:
						  file_writer->WriteLine("Current Zr: " + text);
						  file_writer->WriteLine("-----------------------------");
						  counter++;
						  break;
					  case 22:
						  file_writer->WriteLine("Initial Int: " + text);
						  counter++;
						  break;

					  case 23:
						  file_writer->WriteLine("Current Int: " + text);
						  file_writer->WriteLine("-----------------------------");
						  counter++;
						  break;
					  case 24:
						  file_writer->WriteLine("Initial SW: " + text);
						  counter++;
						  break;

					  case 25:
						  file_writer->WriteLine("Current SW: " + text);
						  file_writer->WriteLine("-----------------------------");
						  counter++;
						  break;
					  case 26:
						  file_writer->WriteLine("Initial Ogd: " + text);
						  counter++;
						  break;

					  case 27:
						  file_writer->WriteLine("Current Ogd: " + text);
						  file_writer->WriteLine("-----------------------------");
						  counter++;
						  break;
					  case 28:
						  file_writer->WriteLine("Initial A: " + text);
						  counter++;
						  break;

					  case 29:
						  file_writer->WriteLine("Current A: " + text);
						  file_writer->WriteLine("-----------------------------");
						  counter++;
						  break;
					  case 30:
						  file_writer->WriteLine("Initial Zyw: " + text);
						  counter++;
						  break;

					  case 31:
						  file_writer->WriteLine("Current Zyw: " + text);
						  file_writer->WriteLine("-----------------------------");
						  counter++;
						  break;
					  case 32:
						  file_writer->WriteLine("Initial S: " + text);
						  counter++;
						  break;

					  case 33:
						  file_writer->WriteLine("Current S: " + text);
						  file_writer->WriteLine("-----------------------------");
						  counter++;
						  break;
					  case 34:
						  file_writer->WriteLine("Initial Wt: " + text);
						  counter++;
						  break;

					  case 35:
						  file_writer->WriteLine("Current Wt: " + text);
						  file_writer->WriteLine("-----------------------------");
						  counter++;
						  break;
					  case 36:
						  file_writer->WriteLine("Initial Sz: " + text);
						  counter++;
						  break;

					  case 37:
						  file_writer->WriteLine("Current Sz: " + text);
						  file_writer->WriteLine("-----------------------------");
						  counter++;
						  break;
					  case 38:
						  file_writer->WriteLine("Initial Mag: " + text);
						  counter++;
						  break;

					  case 39:
						  file_writer->WriteLine("Current Mag: " + text);
						  file_writer->WriteLine("-----------------------------");
						  counter++;
						  break;
					  case 40:
						  file_writer->WriteLine("Initial PO: " + text);
						  counter++;
						  break;

					  case 41:
						  file_writer->WriteLine("Current PO: " + text);
						  file_writer->WriteLine("-----------------------------");
						  counter++;
						  break;
					  case 42:
						  file_writer->WriteLine("Initial PP: " + text);
						  counter++;
						  break;

					  case 43:
						  file_writer->WriteLine("Current PP: " + text);
						  file_writer->WriteLine("==================================");
						  file_writer->WriteLine("==================================");
						  counter++;
						  break;
					  case 44:
						  file_writer->WriteLine("Armor head: " + text);
						  counter++;
						  break;
					  case 45:
						  file_writer->WriteLine("Armor body: " + text);
						  counter++;
						  break;
					  case 46:
						  file_writer->WriteLine("Right hand: " + text);
						  counter++;
						  break;
					  case 47:
						  file_writer->WriteLine("Left hand: " + text);
						  counter++;
						  break;
					  case 48:
						  file_writer->WriteLine("Right leg: " + text);
						  counter++;
						  break;
					  case 49:
						  file_writer->WriteLine("Left leg: " + text);
						  file_writer->WriteLine("==================================");
						  file_writer->WriteLine("==================================");
						  break;



					  default:
						  throw gcnew System::Exception("Invalid counter value!");
					  }
				  }
				  else
				  {
					  MessageBox::Show("Can not open a file", "ERROR", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				  }

			  }
			  catch (Exception^ ex)
			  {
				  MessageBox::Show(ex->Message, "ERROR", MessageBoxButtons::OK, MessageBoxIcon::Error);
			  }


		  }
		  //save hero

		  Void CreateHero::saveAllToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	//save all text boxes to file
	//hero
	save_text_tofile(textbox_name->Text);
	save_text_tofile(textbox_race->Text);
	save_text_tofile(textbox_cur_prof->Text);
	save_text_tofile(textbox_prev_prof->Text);
	//hero desc
	save_text_tofile(textbox_age->Text);
	save_text_tofile(textbox_sex->Text);
	save_text_tofile(textbox_height->Text);
	save_text_tofile(textbox_weight->Text);
	save_text_tofile(textbox_siblings->Text);
	save_text_tofile(textbox_star_sign->Text);
	save_text_tofile(textbox_birthplace->Text);
	//main features
	save_text_tofile(textbox_WWa->Text);
	save_text_tofile(textbox_WWc->Text);
	save_text_tofile(textbox_USa->Text);
	save_text_tofile(textbox_USc->Text);
	save_text_tofile(textbox_Ka->Text);
	save_text_tofile(textbox_Kc->Text);
	save_text_tofile(textbox_ODPa->Text);
	save_text_tofile(textbox_ODPc->Text);
	save_text_tofile(textbox_ZRa->Text);
	save_text_tofile(textbox_ZRc->Text);
	save_text_tofile(textbox_INTa->Text);
	save_text_tofile(textbox_INTc->Text);
	save_text_tofile(textbox_SWa->Text);
	save_text_tofile(textbox_SWc->Text);
	save_text_tofile(textbox_OGDa->Text);
	save_text_tofile(textbox_OGDc->Text);
	//secondary features
	save_text_tofile(textbox_Aa->Text);
	save_text_tofile(textbox_Ac->Text);
	save_text_tofile(textbox_ZYWa->Text);
	save_text_tofile(textbox_ZYWc->Text);
	save_text_tofile(textbox_Sa->Text);
	save_text_tofile(textbox_Sc->Text);
	save_text_tofile(textbox_WTa->Text);
	save_text_tofile(textbox_WTc->Text);
	save_text_tofile(textbox_SZa->Text);
	save_text_tofile(textbox_SZc->Text);
	save_text_tofile(textbox_MAGa->Text);
	save_text_tofile(textbox_MAGc->Text);
	save_text_tofile(textbox_POa->Text);
	save_text_tofile(textbox_POc->Text);
	save_text_tofile(textbox_PPa->Text);
	save_text_tofile(textbox_PPc->Text);
	//armor
	save_text_tofile(tb_headarmor->Text);
	save_text_tofile(tb_bodyarmor->Text);
	save_text_tofile(tb_rhandarmor->Text);
	save_text_tofile(tb_lefthandarmor->Text);
	save_text_tofile(tb_rightfarmor->Text);
	save_text_tofile(tb_leftfootarrmor->Text);


	//message user all changes have been saved
	MessageBox::Show("Changes have been saved", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
	counter = 1;

}
	   //save hero items
		  Void CreateHero::saveToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	save_text_tofile(textbox_name->Text);
	save_text_tofile(textbox_race->Text);
	save_text_tofile(textbox_cur_prof->Text);
	save_text_tofile(textbox_prev_prof->Text);
	//message user that all changes have been saved and make counter default value
	MessageBox::Show("Changes have been saved", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
	counter = 1;
}
	   //save hero desc items
		  Void CreateHero::saveToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
	counter = 5;
	//hero desc
	save_text_tofile(textbox_age->Text);
	save_text_tofile(textbox_sex->Text);
	save_text_tofile(textbox_height->Text);
	save_text_tofile(textbox_weight->Text);
	save_text_tofile(textbox_siblings->Text);
	save_text_tofile(textbox_star_sign->Text);
	save_text_tofile(textbox_birthplace->Text);
	//message user that all changes have been saved and make counter default value
	MessageBox::Show("Changes have been saved", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
	counter = 1;

}
		  Void CreateHero::saveToolStripMenuItem2_Click(System::Object^ sender, System::EventArgs^ e) {
	counter = 12;
	//main features
	save_text_tofile(textbox_WWa->Text);
	save_text_tofile(textbox_WWc->Text);
	save_text_tofile(textbox_USa->Text);
	save_text_tofile(textbox_USc->Text);
	save_text_tofile(textbox_Ka->Text);
	save_text_tofile(textbox_Kc->Text);
	save_text_tofile(textbox_ODPa->Text);
	save_text_tofile(textbox_ODPc->Text);
	save_text_tofile(textbox_ZRa->Text);
	save_text_tofile(textbox_ZRc->Text);
	save_text_tofile(textbox_INTa->Text);
	save_text_tofile(textbox_INTc->Text);
	save_text_tofile(textbox_SWa->Text);
	save_text_tofile(textbox_SWc->Text);
	save_text_tofile(textbox_OGDa->Text);
	save_text_tofile(textbox_OGDc->Text);
	//secondary features
	save_text_tofile(textbox_Aa->Text);
	save_text_tofile(textbox_Ac->Text);
	save_text_tofile(textbox_ZYWa->Text);
	save_text_tofile(textbox_ZYWc->Text);
	save_text_tofile(textbox_Sa->Text);
	save_text_tofile(textbox_Sc->Text);
	save_text_tofile(textbox_WTa->Text);
	save_text_tofile(textbox_WTc->Text);
	save_text_tofile(textbox_SZa->Text);
	save_text_tofile(textbox_SZc->Text);
	save_text_tofile(textbox_MAGa->Text);
	save_text_tofile(textbox_MAGc->Text);
	save_text_tofile(textbox_POa->Text);
	save_text_tofile(textbox_POc->Text);
	save_text_tofile(textbox_PPa->Text);
	save_text_tofile(textbox_PPc->Text);
	//message user that all changes have been saved and make counter default value
	MessageBox::Show("Changes have been saved", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
	counter = 1;
}
		  Void CreateHero::saveToolStripMenuItem3_Click(System::Object^ sender, System::EventArgs^ e) {
			  counter = 44;
	//armor
	save_text_tofile(tb_headarmor->Text);
	save_text_tofile(tb_bodyarmor->Text);
	save_text_tofile(tb_rhandarmor->Text);
	save_text_tofile(tb_lefthandarmor->Text);
	save_text_tofile(tb_rightfarmor->Text);
	save_text_tofile(tb_leftfootarrmor->Text);
	//message user that all changes have been saved and make counter default value
	MessageBox::Show("Changes have been saved", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
	counter = 1;
}

	   //randomaize all stats
Void CreateHero::randomAllToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	//textbox random hero_name
	sex = random_number->Next(2);
	if (sex)
	{
		textbox_name->Text = men_names[random_number->Next(19)];
	}
	else
	{
		textbox_name->Text = women_names[random_number->Next(19)];
	}
	//random hero race
	race_index = random_number->Next(5);
	textbox_race->Text = hero_races[race_index];
	//random hero proffesion
	textbox_cur_prof->Text = hero_profession[random_number->Next(19)];
	do {
		textbox_prev_prof->Text = hero_profession[random_number->Next(19)];
	} while (textbox_prev_prof->Text == textbox_cur_prof->Text);
	//random age

	random_age = random_number->Next(18, 101);
	age_str = random_age.ToString();
	textbox_age->Text = age_str;
	//random height
	random_height;
	switch (race_index)
	{
	case 0: // Human
		random_height = random_number->Next(160, 191);
		break;
	case 1: // Elf
		random_height = random_number->Next(170, 201);
		break;
	case 2: // Dwarf
		random_height = random_number->Next(130, 161);
		break;
	case 3: // Orc
		random_height = random_number->Next(180, 211);
		break;
	case 4: // Undead
		random_height = random_number->Next(160, 191);
		break;
	case 5: // Halfling
		random_height = random_number->Next(90, 121);
		break;
	default:
		random_height = random_number->Next(140, 211);
		break;
	}
	//random sex
	if (sex)
	{
		textbox_sex->Text = "Men";
	}
	else
	{
		textbox_sex->Text = "Women";
		random_height -= 10;
	}
	//convert height to string and paste to text box
	height_str = random_height.ToString();
	textbox_height->Text = height_str;

	//random weight in kg
	random_weight;
	switch (race_index)
	{
	case 0: // Human
		random_weight = random_number->Next(50, 101);
		break;
	case 1: // Elf
		random_weight = random_number->Next(40, 81);
		break;
	case 2: // Dwarf
		random_weight = random_number->Next(60, 111);
		break;
	case 3: // Orc
		random_weight = random_number->Next(80, 151);
		break;
	case 4: // Undead
		random_weight = random_number->Next(40, 81);
		break;
	case 5: // Halfling
		random_weight = random_number->Next(30, 71);
		break;
	default: //index out of range
		random_weight = random_number->Next(40, 151);
		break;
	}
	weight_str = random_weight.ToString();
	textbox_weight->Text = weight_str;

	//hero star sign
	textbox_star_sign->Text = hero_star_sign[random_number->Next(6)];

	//hero place of birth
	textbox_birthplace->Text = hero_star_sign[random_number->Next(6)];

	//hero siblings
	siblings = random_number->Next(6);
	siblings_str = siblings.ToString();
	textbox_siblings->Text = siblings_str;

	//features
	//WW
	features = random_number->Next(30, 81);
	WW = features;
	textbox_WWa->Text = features.ToString();
	//US
	features = random_number->Next(30, 81);
	US = features;
	textbox_USa->Text = features.ToString();
	//K
	features = random_number->Next(30, 81);
	K = features;
	textbox_Ka->Text = features.ToString();
	//Odp
	features = random_number->Next(30, 81);
	ODP = features;
	textbox_ODPa->Text = features.ToString();
	//Zr
	features = random_number->Next(30, 81);
	ZR = features;
	textbox_ZRa->Text = features.ToString();
	//Int
	features = random_number->Next(30, 81);
	INT = features;
	textbox_INTa->Text = features.ToString();
	//SW
	features = random_number->Next(30, 81);
	SW = features;
	textbox_SWa->Text = features.ToString();
	//Ogd
	features = random_number->Next(30, 81);
	OGD = features;
	textbox_OGDa->Text = features.ToString();
	//A
	features = random_number->Next(1, 2);
	textbox_Aa->Text = features.ToString();
	//Zyw
	features = random_number->Next(8, 14);
	textbox_ZYWa->Text = features.ToString();
	//S
	features = random_number->Next(1, 5);
	textbox_Sa->Text = features.ToString();
	//Wt
	features = random_number->Next(1, 4);
	textbox_WTa->Text = features.ToString();
	//Sz
	features = random_number->Next(1, 10);
	textbox_SZa->Text = features.ToString();
	//Mag
	features = random_number->Next(1, 11);
	textbox_MAGa->Text = features.ToString();
	//PO
	features = random_number->Next(1, 10);
	textbox_POa->Text = features.ToString();
	//PP
	features = random_number->Next(1, 3);
	textbox_PPa->Text = features.ToString();
	//ARMOR POINTS
	//head
	features = random_number->Next(1, 6);
	tb_headarmor->Text = features.ToString();
	//body
	features = random_number->Next(1, 6);
	tb_bodyarmor->Text = features.ToString();
	//left arm
	features = random_number->Next(1, 6);
	tb_lefthandarmor->Text = features.ToString();
	//right arm
	features = random_number->Next(1, 6);
	tb_rhandarmor->Text = features.ToString();
	//left leg
	features = random_number->Next(1, 6);
	tb_leftfootarrmor->Text = features.ToString();
	//right leg
	features = random_number->Next(1, 6);
	tb_rightfarmor->Text = features.ToString();
}

	   //RANDOM STATS IN DIFRENT PANELS SEPARATELY
void CreateHero::CompareAndShowResult(int textbox_int, int comparenumber) {
	if (textbox_int >= comparenumber && comparenumber > 10) {
		MessageBox::Show("Roll: " + comparenumber, "Success!", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	else if (textbox_int < comparenumber && comparenumber < 90) {
		MessageBox::Show("Roll: " + comparenumber, "Defeat", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	else if (textbox_int >= comparenumber && comparenumber <= 10) {
		MessageBox::Show("Roll: " + comparenumber, "Critical Success!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
	else if (textbox_int < comparenumber && comparenumber >= 90) {
		MessageBox::Show("Roll: " + comparenumber, "Critical Defeat", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}

Void CreateHero::randomToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	//hero stats
	//textbox random hero_name
	sex = random_number->Next(2);
	if (sex)
	{
		textbox_name->Text = men_names[random_number->Next(19)];
	}
	else
	{
		textbox_name->Text = women_names[random_number->Next(19)];
	}
	//random hero race
	race_index = random_number->Next(5);
	textbox_race->Text = hero_races[race_index];
	//random hero proffesion
	textbox_cur_prof->Text = hero_profession[random_number->Next(19)];
	do {
		textbox_prev_prof->Text = hero_profession[random_number->Next(19)];
	} while (textbox_prev_prof->Text == textbox_cur_prof->Text);
}
	   //hero desc
Void CreateHero::randomStatsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	//random age
	random_age = random_number->Next(18, 101);
	age_str = random_age.ToString();
	textbox_age->Text = age_str;
	//random sex

	if (sex)
	{
		textbox_sex->Text = "Men";
	}
	else
	{
		textbox_sex->Text = "Women";
	}

	//random height in cm
	random_height;
	race_index = random_number->Next(1, 6);
	switch (race_index)
	{
	case 0: // Human
		random_height = random_number->Next(160, 191);
		break;
	case 1: // Elf
		random_height = random_number->Next(170, 201);
		break;
	case 2: // Dwarf
		random_height = random_number->Next(130, 161);
		break;
	case 3: // Orc
		random_height = random_number->Next(180, 211);
		break;
	case 4: // Undead
		random_height = random_number->Next(160, 191);
		break;
	case 5: // Halfling
		random_height = random_number->Next(90, 121);
		break;
	default:
		random_height = random_number->Next(140, 211);
		break;
	}
	height_str = random_height.ToString();
	textbox_height->Text = height_str;

	//random weight in kg
	random_weight;
	switch (race_index)
	{
	case 0: // Human
		random_weight = random_number->Next(50, 101);
		break;
	case 1: // Elf
		random_weight = random_number->Next(40, 81);
		break;
	case 2: // Dwarf
		random_weight = random_number->Next(60, 111);
		break;
	case 3: // Orc
		random_weight = random_number->Next(80, 151);
		break;
	case 4: // Undead
		random_weight = random_number->Next(40, 81);
		break;
	case 5: // Halfling
		random_weight = random_number->Next(30, 71);
		break;
	default: // Jeœli indeks jest poza zakresem
		random_weight = random_number->Next(40, 151);
		break;
	}
	weight_str = random_weight.ToString();
	textbox_weight->Text = weight_str;

	//hero star sign
	textbox_star_sign->Text = men_names[random_number->Next(6)];

	//hero place of birth
	textbox_birthplace->Text = men_names[random_number->Next(6)];

	//hero siblings
	siblings = random_number->Next(6);
	siblings_str = siblings.ToString();
	textbox_siblings->Text = siblings_str;
}
	   //features
Void CreateHero::randomToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
	features = random_number->Next(30, 81);
	WW = features;
	textbox_WWa->Text = features.ToString();
	//US
	features = random_number->Next(30, 81);
	US = features;
	textbox_USa->Text = features.ToString();
	//K
	features = random_number->Next(30, 81);
	K = features;
	textbox_Ka->Text = features.ToString();
	//Odp
	features = random_number->Next(30, 81);
	ODP = features;
	textbox_ODPa->Text = features.ToString();
	//Zr
	features = random_number->Next(30, 81);
	ZR = features;
	textbox_ZRa->Text = features.ToString();
	//Int
	features = random_number->Next(30, 81);
	INT = features;
	textbox_INTa->Text = features.ToString();
	//SW
	features = random_number->Next(30, 81);
	SW = features;
	textbox_SWa->Text = features.ToString();
	//Ogd
	features = random_number->Next(30, 81);
	OGD = features;
	textbox_OGDa->Text = features.ToString();
	//A
	features = random_number->Next(1, 2);
	textbox_Aa->Text = features.ToString();
	//Zyw
	features = random_number->Next(8, 14);
	textbox_ZYWa->Text = features.ToString();
	//S
	features = random_number->Next(1, 5);
	textbox_Sa->Text = features.ToString();
	//Wt
	features = random_number->Next(1, 4);
	textbox_WTa->Text = features.ToString();
	//Sz
	features = random_number->Next(1, 10);
	textbox_SZa->Text = features.ToString();
	//Mag
	features = random_number->Next(1, 11);
	textbox_MAGa->Text = features.ToString();
	//PO
	features = random_number->Next(1, 101);
	textbox_POa->Text = features.ToString();
	//PP
	features = random_number->Next(1, 3);
	textbox_PPa->Text = features.ToString();
}
	   //armor points
Void CreateHero::randomStatsToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
	//ARMOR POINTS
	//head
	features = random_number->Next(1, 6);
	tb_headarmor->Text = features.ToString();
	//body
	features = random_number->Next(1, 6);
	tb_bodyarmor->Text = features.ToString();
	//left arm
	features = random_number->Next(1, 6);
	tb_lefthandarmor->Text = features.ToString();
	//right arm
	features = random_number->Next(1, 6);
	tb_rhandarmor->Text = features.ToString();
	//left leg
	features = random_number->Next(1, 6);
	tb_leftfootarrmor->Text = features.ToString();
	//right leg
	features = random_number->Next(1, 6);
	tb_rightfarmor->Text = features.ToString();
}

	   //make test 
	   //funkction to check wheter test is passed or lost
	   void CompareAndShowResult(int textbox_int, int comparenumber) {
		   if (textbox_int >= comparenumber && comparenumber > 10) {
			   MessageBox::Show("Roll: " + comparenumber, "Success!", MessageBoxButtons::OK, MessageBoxIcon::Information);
		   }
		   else if (textbox_int < comparenumber && comparenumber < 90) {
			   MessageBox::Show("Roll: " + comparenumber, "Defeat", MessageBoxButtons::OK, MessageBoxIcon::Error);
		   }
		   else if (textbox_int >= comparenumber && comparenumber <= 10) {
			   MessageBox::Show("Roll: " + comparenumber, "Critical Success!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		   }
		   else if (textbox_int < comparenumber && comparenumber >= 90) {
			   MessageBox::Show("Roll: " + comparenumber, "Critical Defeat", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		   }
	   }
	   Void CreateHero::sword_WW_Click(System::Object^ sender, System::EventArgs^ e) {
	comparenumber = random_comparenumber->Next(1, 101);
	// check if the input textbox is empty or the entered value is invalid
	if (textbox_WWa->Text == "" || !Int32::TryParse(textbox_WWa->Text, WW) || WW <= 0 || WW > 100)
	{
		MessageBox::Show("Fill textbox with a correct number WWa nie dziala  (1-100)", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	// check if the textbox for modified value is not empty and the entered value is valid
	else if (textbox_WWc->Text != "" && Int32::TryParse(textbox_WWc->Text, WW) && WW > 0 && WW <= 100)
	{
		WW = Convert::ToInt32(textbox_WWc->Text);
		CompareAndShowResult(WW, comparenumber);
	}
	else
	{
		CompareAndShowResult(WW, comparenumber); // call the function to compare and show the result
	}
}
	   Void CreateHero::sword_US_Click(System::Object^ sender, System::EventArgs^ e) {
	comparenumber = random_comparenumber->Next(1, 101);

	// check if the input textbox is empty or the entered value is invalid
	if (textbox_USa->Text == "" || !Int32::TryParse(textbox_USa->Text, US) || US <= 0 || US > 100)
	{
		MessageBox::Show("Fill the textbox with a correct number (1-100)", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	// check if the textbox for modified value is not empty and the entered value is valid
	else if (textbox_USc->Text != "" && Int32::TryParse(textbox_USc->Text, US) && US > 0 && US <= 100)
	{
		US = Convert::ToInt32(textbox_USc->Text);
		CompareAndShowResult(US, comparenumber); // Call the function to compare and show the result
	}
	// if none of the above conditions are met, use the original value of US for comparison
	else
	{
		CompareAndShowResult(US, comparenumber); // call the function to compare and show the result
	}
}
	   Void CreateHero::sword_K_Click(System::Object^ sender, System::EventArgs^ e) {
	
	 comparenumber = random_comparenumber->Next(1, 101);
	// check if the input textbox is empty or the entered value is invalid
	if (textbox_Ka->Text == "" || !Int32::TryParse(textbox_Ka->Text, K) || K <= 0 || K > 100)
	{
		MessageBox::Show("Fill the textbox with a correct number (1-100)", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	// check if the textbox for modified value is not empty and the entered value is valid
	else if (textbox_Kc->Text != "" && Int32::TryParse(textbox_Kc->Text, K) && K > 0 && K <= 100)
	{
		K = Convert::ToInt32(textbox_Kc->Text);
		CompareAndShowResult(K, comparenumber); // Call the function to compare and show the result
	}
	// if none of the above conditions are met, use the original value of k for comparison
	else
	{
		CompareAndShowResult(K, comparenumber); // call the function to compare and show the result
	}
}
	   Void CreateHero::sword_ODP_Click(System::Object^ sender, System::EventArgs^ e) {
    comparenumber = random_comparenumber->Next(1, 101);

	// Check if the input textbox is empty or the entered value is invalid
	if (textbox_ODPa->Text == "" || !Int32::TryParse(textbox_ODPa->Text, ODP) || ODP <= 0 || ODP > 100) {
		MessageBox::Show("Fill the textbox with a correct number (1-100)", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	// Check if the textbox for modified value is not empty and the entered value is valid
	else if (textbox_ODPc->Text != "" && Int32::TryParse(textbox_ODPc->Text, ODP) && ODP > 0 && ODP <= 100) {
		ODP = Convert::ToInt32(textbox_ODPc->Text);
		CompareAndShowResult(ODP, comparenumber); // Call the function to compare and show the result
	}
	// If none of the above conditions are met, use the original value of ODP for comparison
	else {
		CompareAndShowResult(ODP, comparenumber); // Call the function to compare and show the result
	}
}

	   Void CreateHero::sword_ZR_Click(System::Object^ sender, System::EventArgs^ e) {

	 comparenumber = random_comparenumber->Next(1, 101);

	// check if the input textbox is empty or the entered value is invalid
	if (textbox_ZRa->Text == "" || !Int32::TryParse(textbox_ZRa->Text, ZR) || ZR <= 0 || ZR > 100)
	{
		MessageBox::Show("Fill the textbox with a correct number (1-100)", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	// check if the textbox for modified value is not empty and the entered value is valid
	else if (textbox_ZRc->Text != "" && Int32::TryParse(textbox_ZRc->Text, ZR) && ZR > 0 && ZR <= 100)
	{
		ZR = Convert::ToInt32(textbox_ZRc->Text);
		CompareAndShowResult(ZR, comparenumber); // Call the function to compare and show the result
	}
	// if none of the above conditions are met, use the original value of ZR for comparison
	else
	{
		CompareAndShowResult(ZR, comparenumber); // Call the function to compare and show the result
	}
}
	   Void CreateHero::sword_INT_Click(System::Object^ sender, System::EventArgs^ e) {
	comparenumber = random_comparenumber->Next(1, 101);

	// check if the input textbox is empty or the entered value is invalid
	if (textbox_INTa->Text == "" || !Int32::TryParse(textbox_INTa->Text, INT) || INT <= 0 || INT > 100)
	{
		MessageBox::Show("Fill the textbox with a correct number (1-100)", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	// check if the textbox for modified value is not empty and the entered value is valid
	else if (textbox_INTc->Text != "" && Int32::TryParse(textbox_INTc->Text, INT) && INT > 0 && INT <= 100)
	{
		INT = Convert::ToInt32(textbox_INTc->Text);
		CompareAndShowResult(INT, comparenumber); // Call the function to compare and show the result
	}
	// if none of the above conditions are met, use the original value of INT for comparison
	else
	{
		CompareAndShowResult(INT, comparenumber); // Call the function to compare and show the result
	}
}
	   Void CreateHero::sword_SW_Click(System::Object^ sender, System::EventArgs^ e) {
	comparenumber = random_comparenumber->Next(1, 101);

	// check if the input textbox is empty or the entered value is invalid
	if (textbox_SWa->Text == "" || !Int32::TryParse(textbox_SWa->Text, SW) || SW <= 0 || SW > 100)
	{
		MessageBox::Show("Fill the textbox with a correct number (1-100)", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	// check if the textbox for modified value is not empty and the entered value is valid
	else if (textbox_SWc->Text != "" && Int32::TryParse(textbox_SWc->Text, SW) && SW > 0 && SW <= 100)
	{
		SW = Convert::ToInt32(textbox_SWc->Text);
		CompareAndShowResult(SW, comparenumber); // Call the function to compare and show the result
	}
	// if none of the above conditions are met, use the original value of SW for comparison
	else
	{
		CompareAndShowResult(SW, comparenumber); // Call the function to compare and show the result
	}
}
	   Void CreateHero::sword_OGD_Click(System::Object^ sender, System::EventArgs^ e) {
	comparenumber = random_comparenumber->Next(1, 101);

	// check if the input textbox is empty or the entered value is invalid
	if (textbox_OGDa->Text == "" || !Int32::TryParse(textbox_OGDa->Text, OGD) || OGD <= 0 || OGD > 100) {
		MessageBox::Show("Fill the textbox with a correct number (1-100)", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	// check if the textbox for modified value is not empty and the entered value is valid
	else if (textbox_OGDc->Text != "" && Int32::TryParse(textbox_OGDc->Text, OGD) && OGD > 0 && OGD <= 100) {
		OGD = Convert::ToInt32(textbox_OGDc->Text);
		CompareAndShowResult(OGD, comparenumber); // Call the function to compare and show the result
	}
	// if none of the above conditions are met, use the original value of OGD for comparison
	else {
		CompareAndShowResult(OGD, comparenumber); // Call the function to compare and show the result

	}
}

	   //ADD +5 FETURES OR - +5 FEATURES
	   //WW +
	   Void CreateHero::pictureBox_plus1_Click(System::Object^ sender, System::EventArgs^ e) {
	//check whether textbox a is empty or can not be changed to int or is bigger than 100 or lower than 0
	// if yes sent message box otherwise change to int than add to WW variable
	if (textbox_WWa->Text == "" || !Int32::TryParse(textbox_WWa->Text, WW) || WW <= 0 || WW > 100)
	{
		MessageBox::Show("Fill textbox with a correct number (1-100)", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	else if (textbox_WWc->Text != "")
	{
		WW = Convert::ToInt32(textbox_WWc->Text);
		if (WW < 95)
		{
			WW += 5;
			String^ WW_add = Convert::ToString(WW);
			textbox_WWc->Text = WW_add;
		}
		else
		{
			MessageBox::Show("WW  cannot exceed 99", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	else
	{
		WW = Convert::ToInt32(textbox_WWa->Text);
		if (WW < 95)
		{
			WW += 5;
			String^ WW_add = Convert::ToString(WW);
			textbox_WWc->Text = WW_add;
		}
		else
		{
			MessageBox::Show("WW cannot exceed 99", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			textbox_WWc->Text = "";
			WW = -1;
		}
	}
}
	   //decreamante 5 from feature
	   //WW -
	   Void CreateHero::pictureBox_minus1_Click(System::Object^ sender, System::EventArgs^ e) {
	//check whether textbox a is empty or can not be changed to int or is bigger than 100 or lower than 0
	// if yes sent message box otherwise change to int than add to WW variable
	if (textbox_WWa->Text == "" || !Int32::TryParse(textbox_WWa->Text, WW) || WW <= 0 || WW > 100)
	{
		MessageBox::Show("Fill textbox with a correct number (1-100)", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	else if (textbox_WWc->Text != "")
	{
		WW = Convert::ToInt32(textbox_WWc->Text);
		if (WW >= 5)
		{
			WW -= 5;
			String^ WW_add = Convert::ToString(WW);
			textbox_WWc->Text = WW_add;
		}
		else
		{
			MessageBox::Show("WW cannot be less than 0", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	else
	{
		WW = Convert::ToInt32(textbox_WWa->Text);
		if (WW >= 5)
		{
			WW -= 5;
			String^ WW_add = Convert::ToString(WW);
			textbox_WWc->Text = WW_add;
		}
		else
		{
			MessageBox::Show("WW cannot be less than 0", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			textbox_WWc->Text = "";
			WW = -1;
		}
	}
}
	   //WW TEXT CHANGED
	   Void CreateHero::textbox_WWa_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		   // Check if textbox_WWa is empty or can be converted to int; if yes, update WW variable
		   textbox_WWc->Text = "";
		   WW = -1;
	   }
			  //US +
	   Void CreateHero::pictureBox_plus2_Click(System::Object^ sender, System::EventArgs^ e) {
	// Check if textbox_USa is valid (not empty, a valid integer between 1 and 100)
	if (textbox_USa->Text == "" || !Int32::TryParse(textbox_USa->Text, US) || US <= 0 || US > 100)
	{
		// Show error message if textbox_USa is not valid
		MessageBox::Show("Fill textbox with a correct number (1-100)", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	else if (textbox_USc->Text != "")
	{
		// Check if textbox_USc is not empty
		US = Convert::ToInt32(textbox_USc->Text);
		// Check if US is less than or equal to 95
		if (US < 95)
		{
			// Add 5 to US and update textbox_USc
			US += 5;
			textbox_USc->Text = Convert::ToString(US);
		}
		else
		{
			// Show error message if US is greater than 100
			MessageBox::Show("US cannot exceed 100", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	else
	{
		// Update US based on textbox_USa
		US = Convert::ToInt32(textbox_USa->Text);
		// Check if US is less than or equal to 95
		if (US < 95)
		{
			// Add 5 to US and update textbox_USc
			US += 5;
			textbox_USc->Text = Convert::ToString(US);
		}
		else
		{
			// Show error message if US is greater than 100
			MessageBox::Show("US cannot exceed 100", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			textbox_USc->Text = "";
			US = 0;
		}
	}
}
	   //US -
	   Void CreateHero::pictureBox_minus2_Click(System::Object^ sender, System::EventArgs^ e) {
	// Check if textbox_USa is valid (not empty, a valid integer between 1 and 100)
	if (textbox_USa->Text == "" || !Int32::TryParse(textbox_USa->Text, US) || US <= 0 || US > 100)
	{
		// Show error message if textbox_USa is not valid
		MessageBox::Show("Fill textbox with a correct number (1-100)", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	else if (textbox_USc->Text != "")
	{
		// Check if textbox_USc is not empty
		US = Convert::ToInt32(textbox_USc->Text);
		// Check if US is greater than or equal to 5
		if (US >= 5)
		{
			// Subtract 5 from US and update textbox_USc
			US -= 5;
			textbox_USc->Text = Convert::ToString(US);
		}
		else
		{
			// Show error message if US is less than 5
			MessageBox::Show("US cannot be less than 0", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	else
	{
		// Update US based on textbox_US
		US = Convert::ToInt32(textbox_USa->Text);
		// Check if US is greater than or equal to 5
		if (US >= 5)
		{
			// Subtract 5 from US and update textbox_USc
			US -= 5;
			textbox_USc->Text = Convert::ToString(US);
		}
		else
		{
			// Show error message if US is less than 5
			MessageBox::Show("US cannot be less than 0", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			textbox_USc->Text = "";
			US = 0;
		}
	}
}
	   Void CreateHero::textbox_USa_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		   textbox_USc->Text = "";
		   US = 0;
	   }
			  //K +
			  Void CreateHero::pictureBox_plus3_Click(System::Object^ sender, System::EventArgs^ e) {
	// Check if textbox_Ka contains a valid number (not empty, an integer between 1 and 100)
	if (textbox_Ka->Text == "" || !Int32::TryParse(textbox_Ka->Text, K) || K <= 0 || K > 100)
	{
		// Show an error message if textbox_Ka doesn't contain a valid value
		MessageBox::Show("Fill textbox with a correct number (1-100)", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	else if (textbox_Kc->Text != "")
	{
		// Check if textbox_Kc is not empty
		K = Convert::ToInt32(textbox_Kc->Text);
		// Add 5 to K and update textbox_Kc if K is less than or equal to 95
		if (K < 95)
		{
			K += 5;
			textbox_Kc->Text = Convert::ToString(K);
		}
		else
		{
			// Show an error message if K is greater than 95
			MessageBox::Show("WW cannot exceed 100", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	else
	{
		// Update K based on textbox_Ka
		K = Convert::ToInt32(textbox_Ka->Text);
		// Add 5 to K and update textbox_Kc if K is less than or equal to 95
		if (K < 95)
		{
			K += 5;
			textbox_Kc->Text = Convert::ToString(K);
		}
		else
		{
			// Show an error message if K is greater than 95
			MessageBox::Show("K cannot exceed 100", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			textbox_Kc->Text = "";
			K = 0;
		}
	}
}
	   //K-
			  Void CreateHero::pictureBox_minus3_Click(System::Object^ sender, System::EventArgs^ e) {
	if (textbox_Ka->Text == "" || !Int32::TryParse(textbox_Ka->Text, K) || K <= 0 || K > 100)
	{
		// Show an error message if textbox_Ka doesn't contain a valid value
		MessageBox::Show("Fill textbox with a correct number (1-100)", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	else if (textbox_Kc->Text != "")
	{
		// Check if textbox_Kc is not empty
		K = Convert::ToInt32(textbox_Kc->Text);
		// Subtract 5 from K and update textbox_Kc if K is greater than or equal to 5
		if (K >= 5)
		{
			K -= 5;
			textbox_Kc->Text = Convert::ToString(K);
		}
		else
		{
			// Show an error message if K is less than 5
			MessageBox::Show("K cannot be less than 0", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	else
	{
		// Update K based on textbox_Ka
		K = Convert::ToInt32(textbox_Ka->Text);
		// Subtract 5 from K and update textbox_Kc if K is greater than or equal to 5
		if (K >= 5)
		{
			K -= 5;
			textbox_Kc->Text = Convert::ToString(K);
		}
		else
		{
			// Show an error message if K is less than 5
			MessageBox::Show("K cannot be less than 0", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			textbox_Kc->Text = "";
			K = 0;
		}
	}
}

			  Void CreateHero::textbox_Ka_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	textbox_Kc->Text = "";
	K = 0;
}
	   //ODP +
			  Void CreateHero::pictureBox_plus4_Click(System::Object^ sender, System::EventArgs^ e) {
	// Check if textbox_ODPa contains a valid number (not empty, an integer between 1 and 100)
	if (textbox_ODPa->Text == "" || !Int32::TryParse(textbox_ODPa->Text, ODP) || ODP <= 0 || ODP > 100)
	{
		// Show an error message if textbox_ODPa doesn't contain a valid value
		MessageBox::Show("Fill textbox with a correct number (1-100)", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	else if (textbox_ODPc->Text != "")
	{
		// Check if textbox_ODPc is not empty
		ODP = Convert::ToInt32(textbox_ODPc->Text);
		// Add 5 to ODP and update textbox_ODPc if ODP is less than or equal to 95
		if (ODP < 95)
		{
			ODP += 5;
			textbox_ODPc->Text = Convert::ToString(ODP);
		}
		else
		{
			// Show an error message if ODP is greater than 95
			MessageBox::Show("ODP cannot exceed 100", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	else
	{
		// Update ODP based on textbox_ODPa
		ODP = Convert::ToInt32(textbox_ODPa->Text);
		// Add 5 to ODP and update textbox_ODPc if ODP is less than or equal to 95
		if (ODP < 95)
		{
			ODP += 5;
			textbox_ODPc->Text = Convert::ToString(ODP);
		}
		else
		{
			// Show an error message if ODP is greater than 95
			MessageBox::Show("ODP cannot exceed 100", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			textbox_ODPc->Text = "";
			ODP = 0;
		}
	}
}
			  Void CreateHero::pictureBox_minus4_Click(System::Object^ sender, System::EventArgs^ e) {
	if (textbox_ODPa->Text == "" || !Int32::TryParse(textbox_ODPa->Text, ODP) || ODP <= 0 || ODP > 100)
	{
		// Show an error message if textbox_ODPa doesn't contain a valid value
		MessageBox::Show("Fill textbox with a correct number (1-100)", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	else if (textbox_ODPc->Text != "")
	{
		// Check if textbox_ODPc is not empty
		ODP = Convert::ToInt32(textbox_ODPc->Text);
		// Subtract 5 from ODP and update textbox_ODPc if ODP is greater than or equal to 5
		if (ODP >= 5)
		{
			ODP -= 5;
			textbox_ODPc->Text = Convert::ToString(ODP);
		}
		else
		{
			// Show an error message if ODP is less than 5
			MessageBox::Show("ODP cannot be less than 0", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	else
	{
		// Update ODP based on textbox_ODPa
		ODP = Convert::ToInt32(textbox_ODPa->Text);
		// Subtract 5 from ODP and update textbox_ODPc if ODP is greater than or equal to 5
		if (ODP >= 5)
		{
			ODP -= 5;
			textbox_ODPc->Text = Convert::ToString(ODP);
		}
		else
		{
			// Show an error message if ODP is less than 5
			MessageBox::Show("ODP cannot be less than 0", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error); \
				textbox_ODPc->Text = "";
			ODP = 0;
		}
	}
}
			  Void CreateHero::textbox_ODPa_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	textbox_ODPc->Text = "";
	ODP = 0;
}
	   //ZR +
			  Void CreateHero::pictureBox_plus5_Click(System::Object^ sender, System::EventArgs^ e) {
				  // Checking if textbox_ZRa contains a valid number (is not empty, is an integer between 1 and 100)
				  if (textbox_ZRa->Text == "" || !Int32::TryParse(textbox_ZRa->Text, ZR) || ZR <= 0 || ZR > 100)
				  {
					  // Displaying an error message if textbox_ZRa does not contain a valid value
					  MessageBox::Show("Fill the textbox with a correct number (1-100)", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				  }
				  else if (textbox_ZRc->Text != "")
				  {
					  // Checking if textbox_ZRc is not empty
					  ZR = Convert::ToInt32(textbox_ZRc->Text);
					  // Adding 5 to ZR and updating textbox_ZRc if ZR is less than or equal to 95
					  if (ZR < 95)
					  {
						  ZR += 5;
						  textbox_ZRc->Text = Convert::ToString(ZR);
					  }
					  else
					  {
						  // Displaying an error message if ZR exceeds 95
						  MessageBox::Show("ZR cannot exceed 100", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					  }
				  }
				  else
				  {
					  // Updating ZR based on textbox_ZRa
					  ZR = Convert::ToInt32(textbox_ZRa->Text);
					  // Adding 5 to ZR and updating textbox_ZRc if ZR is less than or equal to 95
					  if (ZR < 95)
					  {
						  ZR += 5;
						  textbox_ZRc->Text = Convert::ToString(ZR);
					  }
					  else
					  {
						  // Displaying an error message if ZR exceeds 95
						  MessageBox::Show("ZR cannot exceed 100", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					  }
				  }
}
	   //ZR -
			  Void CreateHero::pictureBox_minus5_Click(System::Object^ sender, System::EventArgs^ e) {
				  // Checking if textbox_ZRa contains a valid number (is not empty, is an integer between 1 and 100)
				  if (textbox_ZRa->Text == "" || !Int32::TryParse(textbox_ZRa->Text, ZR) || ZR <= 0 || ZR > 100)
				  {
					  // Displaying an error message if textbox_ZRa does not contain a valid value
					  MessageBox::Show("Fill the textbox with a correct number (1-100)", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				  }
				  else if (textbox_ZRc->Text != "")
				  {
					  // Checking if textbox_ZRc is not empty
					  ZR = Convert::ToInt32(textbox_ZRc->Text);
					  // Subtracting 5 from ZR and updating textbox_ZRc if ZR is greater than or equal to 5
					  if (ZR >= 5)
					  {
						  ZR -= 5;
						  textbox_ZRc->Text = Convert::ToString(ZR);
					  }
					  else
					  {
						  // Displaying an error message if ZR is less than 5
						  MessageBox::Show("ZR cannot be less than 0", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					  }
				  }
				  else
				  {
					  // Updating ZR based on textbox_ZRa
					  ZR = Convert::ToInt32(textbox_ZRa->Text);
					  // Subtracting 5 from ZR and updating textbox_ZRc if ZR is greater than or equal to 5
					  if (ZR >= 5)
					  {
						  ZR -= 5;
						  textbox_ZRc->Text = Convert::ToString(ZR);
					  }
					  else
					  {
						  // Displaying an error message if ZR is less than 5
						  MessageBox::Show("ZR cannot be less than 0", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					  }
				  }
}
	   //ZRa text changed
			  Void CreateHero::textbox_ZRa_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	textbox_ZRc->Text = "";
	ZR = 0;
}
	   //INT +
			  Void CreateHero::pictureBox_plus6_Click(System::Object^ sender, System::EventArgs^ e) {
				  // Checking if textbox_INTa contains a valid number (is not empty, is an integer between 1 and 100)
				  if (textbox_INTa->Text == "" || !Int32::TryParse(textbox_INTa->Text, INT) || INT <= 0 || INT > 100)
				  {
					  // Displaying an error message if textbox_INTa does not contain a valid value
					  MessageBox::Show("Fill textbox with a correct number (1-100)", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				  }
				  else if (textbox_INTc->Text != "")
				  {
					  // Checking if textbox_INTc is not empty
					  INT = Convert::ToInt32(textbox_INTc->Text);
					  // Adding 5 to INT and updating textbox_INTc if INT is less than or equal to 95
					  if (INT < 95)
					  {
						  INT += 5;
						  textbox_INTc->Text = Convert::ToString(INT);
					  }
					  else
					  {
						  // Displaying an error message if INT exceeds 95
						  MessageBox::Show("INT cannot exceed 100", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					  }
				  }
				  else
				  {
					  // Updating INT based on textbox_INTa
					  INT = Convert::ToInt32(textbox_INTa->Text);
					  // Adding 5 to INT and updating textbox_INTc if INT is less than or equal to 95
					  if (INT < 95)
					  {
						  INT += 5;
						  textbox_INTc->Text = Convert::ToString(INT);
					  }
					  else
					  {
						  // Displaying an error message if INT exceeds 95
						  MessageBox::Show("INT cannot exceed 100", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					  }
				  }
}
	   //INT -
			  Void CreateHero::pictureBox_minus6_Click(System::Object^ sender, System::EventArgs^ e) {
				  // Checking if textbox_INTa contains a valid number (is not empty, is an integer between 1 and 100)
				  if (textbox_INTa->Text == "" || !Int32::TryParse(textbox_INTa->Text, INT) || INT <= 0 || INT > 100)
				  {
					  // Displaying an error message if textbox_INTa does not contain a valid value
					  MessageBox::Show("Please fill the textbox with a correct number (1-100)", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				  }
				  else if (textbox_INTc->Text != "")
				  {
					  // Checking if textbox_INTc is not empty
					  INT = Convert::ToInt32(textbox_INTc->Text);
					  // Subtracting 5 from INT and updating textbox_INTc if INT is greater than or equal to 5
					  if (INT >= 5)
					  {
						  INT -= 5;
						  textbox_INTc->Text = Convert::ToString(INT);
					  }
					  else
					  {
						  // Displaying an error message if INT is less than 5
						  MessageBox::Show("INT cannot be less than 0", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					  }
				  }
				  else
				  {
					  // Updating INT based on textbox_INTa
					  INT = Convert::ToInt32(textbox_INTa->Text);
					  // Subtracting 5 from INT and updating textbox_INTc if INT is greater than or equal to 5
					  if (INT >= 5)
					  {
						  INT -= 5;
						  textbox_INTc->Text = Convert::ToString(INT);
					  }
					  else
					  {
						  // Displaying an error message if INT is less than 5
						  MessageBox::Show("INT cannot be less than 0", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					  }
				  }
}
	   //INa text changed
			  Void CreateHero::textbox_INTa_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	textbox_INTc->Text = "";
	INT = 0;
}
	   //SW +
			  Void CreateHero::pictureBox_plus7_Click(System::Object^ sender, System::EventArgs^ e) {
				  // Checking if textbox_SWa contains a valid number (is not empty, is an integer between 1 and 100)
				  if (textbox_SWa->Text == "" || !Int32::TryParse(textbox_SWa->Text, SW) || SW <= 0 || SW > 100)
				  {
					  // Displaying an error message if textbox_SWa does not contain a valid value
					  MessageBox::Show("Please enter a valid number (1-100) in the textbox.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				  }
				  else if (textbox_SWc->Text != "")
				  {
					  // Checking if textbox_SWc is not empty
					  SW = Convert::ToInt32(textbox_SWc->Text);
					  // Subtracting 5 from SW and updating textbox_SWc if SW is greater than or equal to 5
					  if (SW >= 5)
					  {
						  SW -= 5;
						  textbox_SWc->Text = Convert::ToString(SW);
					  }
					  else
					  {
						  // Displaying an error message if SW is less than 5
						  MessageBox::Show("SW cannot be less than 0", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					  }
				  }
				  else
				  {
					  // Updating SW based on textbox_SWa
					  SW = Convert::ToInt32(textbox_SWa->Text);
					  // Subtracting 5 from SW and updating textbox_SWc if SW is greater than or equal to 5
					  if (SW >= 5)
					  {
						  SW -= 5;
						  textbox_SWc->Text = Convert::ToString(SW);
					  }
					  else
					  {
						  // Displaying an error message if SW is less than 5
						  MessageBox::Show("SW cannot be less than 0", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					  }
				  }
	
}
	   //SW -
			  Void CreateHero::pictureBox_minus7_Click(System::Object^ sender, System::EventArgs^ e) {
				  // Checking if textbox_SWa contains a valid number (is not empty, is an integer between 1 and 100)
				  if (textbox_SWa->Text == "" || !Int32::TryParse(textbox_SWa->Text, SW) || SW <= 0 || SW > 100)
				  {
					  // Displaying an error message if textbox_SWa does not contain a valid value
					  MessageBox::Show("Fill textbox with a correct number (1-100)", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				  }
				  else if (textbox_SWc->Text != "")
				  {
					  // Checking if textbox_SWc is not empty
					  SW = Convert::ToInt32(textbox_SWc->Text);
					  // Subtracting 5 from SW and updating textbox_SWc if SW is greater than or equal to 5
					  if (SW >= 5)
					  {
						  SW -= 5;
						  textbox_SWc->Text = Convert::ToString(SW);
					  }
					  else
					  {
						  // Displaying an error message if SW is less than 5
						  MessageBox::Show("SW cannot be less than 0", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					  }
				  }
				  else
				  {
					  // Updating SW based on textbox_SWa
					  SW = Convert::ToInt32(textbox_SWa->Text);
					  // Subtracting 5 from SW and updating textbox_SWc if SW is greater than or equal to 5
					  if (SW >= 5)
					  {
						  SW -= 5;
						  textbox_SWc->Text = Convert::ToString(SW);
					  }
					  else
					  {
						  // Displaying an error message if SW is less than 5
						  MessageBox::Show("SW cannot be less than 0", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					  }
				  }
}
	   //SWa text changed
			  Void CreateHero::textbox_SWa_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	textbox_SWc->Text = "";
	SW = 0;
}
	   //OGD +
			  Void CreateHero::pictureBox_plus8_Click(System::Object^ sender, System::EventArgs^ e) {
				  // Checking if textbox_OGDa contains a valid number (is not empty, is an integer between 1 and 100)
				  if (textbox_OGDa->Text == "" || !Int32::TryParse(textbox_OGDa->Text, OGD) || OGD <= 0 || OGD > 100)
				  {
					  // Displaying an error message if textbox_OGDa does not contain a valid value
					  MessageBox::Show("Fill textbox with a correct number (1-100)", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				  }
				  else if (textbox_OGDc->Text != "")
				  {
					  // Checking if textbox_OGDc is not empty
					  OGD = Convert::ToInt32(textbox_OGDc->Text);
					  // Adding 5 to OGD and updating textbox_OGDc if OGD is less than or equal to 95
					  if (OGD < 95)
					  {
						  OGD += 5;
						  textbox_OGDc->Text = Convert::ToString(OGD);
					  }
					  else
					  {
						  // Displaying an error message if OGD exceeds 95
						  MessageBox::Show("OGD cannot exceed 100", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					  }
				  }
				  else
				  {
					  // Updating OGD based on textbox_OGDa
					  OGD = Convert::ToInt32(textbox_OGDa->Text);
					  // Adding 5 to OGD and updating textbox_OGDc if OGD is less than or equal to 95
					  if (OGD < 95)
					  {
						  OGD += 5;
						  textbox_OGDc->Text = Convert::ToString(OGD);
					  }
					  else
					  {
						  // Displaying an error message if OGD exceeds 95
						  MessageBox::Show("OGD cannot exceed 100", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					  }
				  }
}
	   //OGD -
			  Void CreateHero::pictureBox_minus8_Click(System::Object^ sender, System::EventArgs^ e) {
				  // Checking if textbox_OGDa contains a valid number (is not empty, is an integer between 1 and 100)
				  if (textbox_OGDa->Text == "" || !Int32::TryParse(textbox_OGDa->Text, OGD) || OGD <= 0 || OGD > 100)
				  {
					  // Displaying an error message if textbox_OGDa does not contain a valid value
					  MessageBox::Show("Fill textbox with a correct number (1-100)", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				  }
				  else if (textbox_OGDc->Text != "")
				  {
					  // Checking if textbox_OGDc is not empty
					  OGD = Convert::ToInt32(textbox_OGDc->Text);
					  // Subtracting 5 from OGD and updating textbox_OGDc if OGD is greater than or equal to 5
					  if (OGD >= 5)
					  {
						  OGD -= 5;
						  textbox_OGDc->Text = Convert::ToString(OGD);
					  }
					  else
					  {
						  // Displaying an error message if OGD is less than 5
						  MessageBox::Show("OGD cannot be less than 0", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					  }
				  }
				  else
				  {
					  // Updating OGD based on textbox_OGDa
					  OGD = Convert::ToInt32(textbox_OGDa->Text);
					  // Subtracting 5 from OGD and updating textbox_OGDc if OGD is greater than or equal to 5
					  if (OGD >= 5)
					  {
						  OGD -= 5;
						  textbox_OGDc->Text = Convert::ToString(OGD);
					  }
					  else
					  {
						  // Displaying an error message if OGD is less than 5
						  MessageBox::Show("OGD cannot be less than 0", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
						  textbox_OGDc->Text = "";
						  OGD = 0;
					  }
				  }
}
	   //OGDa text changed
			  Void CreateHero::textbox_OGDa_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	textbox_OGDc->Text = "";
	OGD = 0;
}
	   //A +
    Void CreateHero::pictureBox_plus9_Click(System::Object^ sender, System::EventArgs^ e) {

	if (textbox_Aa->Text == "" || !Int32::TryParse(textbox_Aa->Text, A) || A <= 0 || A > 7)
	{
		MessageBox::Show("Fill textbox with a correct number (1-100)", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	else if (textbox_Ac->Text != "")
	{
		A = Convert::ToInt32(textbox_Ac->Text);
		if (A < 7)
		{
			A += 1;
			textbox_Ac->Text = Convert::ToString(A);
		}
		else
		{
			//error message if a is higer than 7
			MessageBox::Show("A cannot exceed 7", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	else
	{
		A = Convert::ToInt32(textbox_Aa->Text);
		if (A < 7)
		{
			A += 1;
			textbox_Ac->Text = Convert::ToString(A);
		}
		else
		{
			MessageBox::Show("A cannot exceed 7", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
}
	   //A -
    Void CreateHero::pictureBox_minus9_Click(System::Object^ sender, System::EventArgs^ e) {
		// Checking if textbox_Aa contains a valid number (is not empty, is an integer between 1 and 100)
		if (textbox_Aa->Text == "" || !Int32::TryParse(textbox_Aa->Text, A) || A <= 0 || A > 7)
		{
			// Displaying an error message if textbox_Aa does not contain a valid value
			MessageBox::Show("Fill textbox with a correct number (1-100)", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else if (textbox_Ac->Text != "")
		{
			// Checking if textbox_Ac is not empty
			A = Convert::ToInt32(textbox_Ac->Text);
			// Adding 1 to A and updating textbox_Ac if A is less than or equal to 7
			if (A > 0)
			{
				A -= 1;
				textbox_Ac->Text = Convert::ToString(A);
			}
			else
			{
				// Displaying an error message if A exceeds 95
				MessageBox::Show("A cannot be less than 0", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		else
		{
			// Updating A based on textbox_Aa
			A = Convert::ToInt32(textbox_Aa->Text);
			// Adding 5 to A and updating textbox_Ac if A is less than or equal to 95
			if (A > 0)
			{
				A -= 1;
				textbox_Ac->Text = Convert::ToString(A);
			}
			else
			{
				MessageBox::Show("A cannot be less than 0", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
}
	   //Aa text changed
	        Void CreateHero::textbox_Aa_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	          textbox_Ac->Text = "";
	          A = 0;
             }
	   //Zyw +
			  Void CreateHero::pictureBox_plus10_Click(System::Object^ sender, System::EventArgs^ e) {
	// Checking if textbox_Aa contains a valid number (not empty, integer between 1 and 100)
	if (textbox_ZYWa->Text == "" || !Int32::TryParse(textbox_ZYWa->Text, ZYW) || ZYW <= 0 || ZYW > 50)
	{
		// Displaying an error message if textbox_Aa does not contain a correct value
		MessageBox::Show("Fill textbox with a correct number (1-50)", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	else if (textbox_ZYWc->Text != "")
	{
		// Checking if textbox_Ac is not empty
		ZYW = Convert::ToInt32(textbox_ZYWc->Text);
		// Adding 5 to A and updating textbox_Ac if A is less than or equal to 95
		if (ZYW < 50)
		{
			ZYW += 1;
			textbox_ZYWc->Text = Convert::ToString(ZYW);
		}
		else
		{
			// Displaying an error message if A exceeds 95
			MessageBox::Show("A cannot exceed 50", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	else
	{
		// Updating A based on textbox_ZYW
		A = Convert::ToInt32(textbox_ZYWa->Text);
		// Adding 5 to A and updating ZYWc if ZYWis less than or equal to 95
		if (ZYW < 50)
		{
			ZYW += 1;
			textbox_ZYWc->Text = Convert::ToString(ZYW);
		}
		else
		{
			// Displaying an error message if ZYW exceeds 50
			MessageBox::Show("A cannot exceed 50", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
}
	   //Zyw -
	          Void CreateHero::pictureBox_minus10_Click(System::Object^ sender, System::EventArgs^ e) {
	// Checking if textbox_Aa contains a valid number (not empty, integer between 1 and 100)
	if (textbox_ZYWa->Text == "" || !Int32::TryParse(textbox_ZYWa->Text, ZYW) || ZYW <= 0 || ZYW > 7)
	{
		// Displaying an error message if textbox_Aa does not contain a correct value
		MessageBox::Show("Fill textbox with a correct number (1-100)", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	else if (textbox_ZYWc->Text != "")
	{
		// Checking if textbox_ZYWc is not empty
		ZYW = Convert::ToInt32(textbox_ZYWc->Text);
		if (ZYW > 0)
		{
			ZYW -= 1;
			textbox_ZYWc->Text = Convert::ToString(ZYW);
		}
		else
		{
			// Displaying an error message if A exceeds 0
			MessageBox::Show("A cannot be less than 0", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	else
	{
		// Updating ZYW based on textbox_ZYWa
		A = Convert::ToInt32(textbox_ZYWa->Text);
		if (ZYW > 0)
		{
			ZYW -= 1;
			textbox_ZYWc->Text = Convert::ToString(ZYW);
		}
		else
		{
			// Displaying an error message if ZYW exceeds 50
			MessageBox::Show("ZYW cannot be less than 0", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
}
	   //ZYWa text changed
			  Void CreateHero::textbox_ZYWa_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	textbox_ZYWc->Text = "";
	ZYW = 0;
}
	   //S +
			  Void CreateHero::pictureBox_plus11_Click(System::Object^ sender, System::EventArgs^ e) {
	// Checking if textbox_Sa contains a valid number (not empty, integer between 1 and 50)
	if (textbox_Sa->Text == "" || !Int32::TryParse(textbox_Sa->Text, S) || S <= 0 || S > 7)
	{
		// Displaying an error message if textbox_Sa does not contain a correct value
		MessageBox::Show("Fill textbox with a correct number (1-7)", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	else if (textbox_Sc->Text != "")
	{
		// Checking if textbox_Sc is not empty
		S = Convert::ToInt32(textbox_Sc->Text);
		// Adding 1 to S and updating textbox_Sc if S is less than 7
		if (S < 7)
		{
			S += 1;
			textbox_Sc->Text = Convert::ToString(S);
		}
		else
		{
			// Displaying an error message if S exceeds 7
			MessageBox::Show("S cannot exceed 7", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	else
	{
		// Updating S based on textbox_Sa
		S = Convert::ToInt32(textbox_Sa->Text);
		// Adding 1 to S and updating Sc if S is less than7
		if (S < 7)
		{
			S += 1;
			textbox_Sc->Text = Convert::ToString(S);
		}
		else
		{
			// Displaying an error message if S exceeds 7
			MessageBox::Show("S cannot exceed 7", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
}
	   //S -
			  Void CreateHero::pictureBox_minus11_Click(System::Object^ sender, System::EventArgs^ e) {
	// Checking if textbox_Sa contains a valid number (not empty, integer between 1 and 50)
	if (textbox_Sa->Text == "" || !Int32::TryParse(textbox_Sa->Text, S) || S <= 0 || S > 7)
	{
		// Displaying an error message if textbox_Sa does not contain a correct value
		MessageBox::Show("Fill textbox with a correct number (1-7)", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	else if (textbox_Sc->Text != "")
	{
		// Checking if textbox_Sc is not empty
		S = Convert::ToInt32(textbox_Sc->Text);
		// Adding 1 to S and updating textbox_Sc if S is less than 50
		if (S > 0)
		{
			S -= 1;
			textbox_Sc->Text = Convert::ToString(S);
		}
		else
		{

			MessageBox::Show("S cannot be less than 0", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	else
	{
		// Updating S based on textbox_Sa
		S = Convert::ToInt32(textbox_Sa->Text);
		// Add
		if (S > 0)
		{
			S -= 1;
			textbox_Sc->Text = Convert::ToString(S);
		}
		else
		{

			MessageBox::Show("S cannot be less than 50", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
}
	   //Sa text changed
			  Void CreateHero::textbox_Sa_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	textbox_Sc->Text = "";
	S = 0;
}
	   //Wt +
Void CreateHero:: pictureBox_plus12_Click(System::Object^ sender, System::EventArgs^ e) {
	if (textbox_WTa->Text == "" || !Int32::TryParse(textbox_WTa->Text, WT) || WT <= 0 || WT > 7)
	{
		// Displaying an error message if textbox_WTa does not contain a correct value
		MessageBox::Show("Fill textbox with a correct number (1-7)", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	else if (textbox_WTc->Text != "")
	{
		// Checking if textbox_WTc is not empty
		WT = Convert::ToInt32(textbox_WTc->Text);
		// Adding 1 to WT and updating textbox_WTc if WT is less than 7
		if (WT < 7)
		{
			WT += 1;
			textbox_WTc->Text = Convert::ToString(WT);
		}
		else
		{
			// Displaying an error message if WT exceeds 7
			MessageBox::Show("WT cannot exceed 7", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	else
	{
		// Updating WT based on textbox_WTa
		WT = Convert::ToInt32(textbox_WTa->Text);
		// Adding 1 to WT and updating textbox_WTc if WT is less than 7
		if (WT < 7)
		{
			WT += 1;
			textbox_WTc->Text = Convert::ToString(WT);
		}
		else
		{
			// Displaying an error message if WT exceeds 7
			MessageBox::Show("WT cannot exceed 7", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

}
	   //Wt -
Void CreateHero::pictureBox_minus12_Click(System::Object^ sender, System::EventArgs^ e) {
	if (textbox_WTa->Text == "" || !Int32::TryParse(textbox_WTa->Text, WT) || WT <= 0 || WT > 7)
	{
		// Displaying an error message if textbox_WTa does not contain a correct value
		MessageBox::Show("Fill textbox with a correct number (1-7)", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	else if (textbox_WTc->Text != "")
	{
		// Checking if textbox_WTc is not empty
		WT = Convert::ToInt32(textbox_WTc->Text);
		// Subtracting 1 from WT and updating textbox_WTc if WT is greater than 0
		if (WT > 0)
		{
			WT -= 1;
			textbox_WTc->Text = Convert::ToString(WT);
		}
		else
		{
			// Displaying an error message if WT is less than 0
			MessageBox::Show("WT cannot be less than 0", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	else
	{
		// Updating WT based on textbox_WTa
		WT = Convert::ToInt32(textbox_WTa->Text);
		// Subtracting 1 from WT and updating textbox_WTc if WT is greater than 0
		if (WT > 0)
		{
			WT -= 1;
			textbox_WTc->Text = Convert::ToString(WT);
		}
		else
		{
			// Displaying an error message if WT is less than 0
			MessageBox::Show("WT cannot be less than 0", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
}
	   //Wt text changed
Void CreateHero::textbox_WTa_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	textbox_WTc->Text = "";
	WT = 0;
}
	   //Sz +
Void CreateHero::pictureBox_plus13_Click(System::Object^ sender, System::EventArgs^ e) {
	if (textbox_SZa->Text == "" || !Int32::TryParse(textbox_SZa->Text, SZ) || SZ <= 0 || SZ > 7)
	{
		// Displaying an error message if textbox_SZa does not contain a correct value
		MessageBox::Show("Fill textbox with a correct number (1-7)", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	else if (textbox_SZc->Text != "")
	{
		// Checking if textbox_SZc is not empty
		SZ = Convert::ToInt32(textbox_SZc->Text);
		// Adding 1 to SZ and updating textbox_SZc if SZ is less than 7
		if (SZ < 7)
		{
			SZ += 1;
			textbox_SZc->Text = Convert::ToString(SZ);
		}
		else
		{
			// Displaying an error message if SZ exceeds 7
			MessageBox::Show("SZ cannot exceed 7", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	else
	{
		// Updating SZ based on textbox_SZa
		SZ = Convert::ToInt32(textbox_SZa->Text);
		// Adding 1 to SZ and updating textbox_SZc if SZ is less than 7
		if (SZ < 7)
		{
			SZ += 1;
			textbox_SZc->Text = Convert::ToString(SZ);
		}
		else
		{
			// Displaying an error message if SZ exceeds 7
			MessageBox::Show("SZ cannot exceed 7", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
}
	   //Sz -
Void CreateHero::pictureBox_minus13_Click(System::Object^ sender, System::EventArgs^ e) {
	// Checking if textbox_SZa contains a valid number (not empty, integer between 1 and 7)
	if (textbox_SZa->Text == "" || !Int32::TryParse(textbox_SZa->Text, SZ) || SZ <= 0 || SZ > 7)
	{
		// Displaying an error message if textbox_SZa does not contain a correct value
		MessageBox::Show("Fill textbox with a correct number (1-7)", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	else if (textbox_SZc->Text != "")
	{
		// Checking if textbox_SZc is not empty
		SZ = Convert::ToInt32(textbox_SZc->Text);
		// Subtracting 1 from SZ and updating textbox_SZc if SZ is greater than 0
		if (SZ > 0)
		{
			SZ -= 1;
			textbox_SZc->Text = Convert::ToString(SZ);
		}
		else
		{
			// Displaying an error message if SZ is less than 0
			MessageBox::Show("SZ cannot be less than 0", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	else
	{
		// Updating SZ based on textbox_SZa
		SZ = Convert::ToInt32(textbox_SZa->Text);
		// Subtracting 1 from SZ and updating textbox_SZc if SZ is greater than 0
		if (SZ > 0)
		{
			SZ -= 1;
			textbox_SZc->Text = Convert::ToString(SZ);
		}
		else
		{
			// Displaying an error message if SZ is less than 0
			MessageBox::Show("SZ cannot be less than 0", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
}
	   //Sz text changed
Void CreateHero::textbox_SZa_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	textbox_SZc->Text = "";
	S = 0;
}
	   //Mag +
Void CreateHero::pictureBox_plus14_Click(System::Object^ sender, System::EventArgs^ e) {
	// Checking if textbox_MAGa contains a valid number (not empty, integer between 1 and 9)
	if (textbox_MAGa->Text == "" || !Int32::TryParse(textbox_MAGa->Text, MAG) || MAG <= 0 || MAG > 9)
	{
		// Displaying an error message if textbox_MAGa does not contain a correct value
		MessageBox::Show("Fill textbox with a correct number (1-9)", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	else if (textbox_MAGc->Text != "")
	{
		// Checking if textbox_MAGc is not empty
		MAG = Convert::ToInt32(textbox_MAGc->Text);
		// Adding 1 to MAG and updating textbox_MAGc if MAG is less than 9
		if (MAG < 9)
		{
			MAG += 1;
			textbox_MAGc->Text = Convert::ToString(MAG);
		}
		else
		{
			// Displaying an error message if MAG exceeds 9
			MessageBox::Show("MAG cannot exceed 9", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	else
	{
		// Updating MAG based on textbox_MAGa
		MAG = Convert::ToInt32(textbox_MAGa->Text);
		// Adding 1 to MAG and updating textbox_MAGc if MAG is less than 9
		if (MAG < 9)
		{
			MAG += 1;
			textbox_MAGc->Text = Convert::ToString(MAG);
		}
		else
		{
			// Displaying an error message if MAG exceeds 9
			MessageBox::Show("MAG cannot exceed 9", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
}
	   //Mag -
Void CreateHero::pictureBox_minus14_Click(System::Object^ sender, System::EventArgs^ e) {
	// Checking if textbox_MAGa contains a valid number (not empty, integer between 1 and 9)
	if (textbox_MAGa->Text == "" || !Int32::TryParse(textbox_MAGa->Text, MAG) || MAG <= 0 || MAG >= 10)
	{
		// Displaying an error message if textbox_MAGa does not contain a correct value
		MessageBox::Show("Fill textbox with a correct number (1-9)", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	else if (textbox_MAGc->Text != "")
	{
		// Checking if textbox_MAGc is not empty
		MAG = Convert::ToInt32(textbox_MAGc->Text);
		// Subtracting 1 from MAG and updating textbox_MAGc if MAG is greater than 0
		if (MAG > 0)
		{
			MAG -= 1;
			textbox_MAGc->Text = Convert::ToString(MAG);
		}
		else
		{
			// Displaying an error message if MAG is less than 0
			MessageBox::Show("MAG cannot be less than 0", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	else
	{
		// Updating MAG based on textbox_MAGa
		MAG = Convert::ToInt32(textbox_MAGa->Text);
		// Subtracting 1 from MAG and updating textbox_MAGc if MAG is greater than 0
		if (MAG > 0)
		{
			MAG -= 1;
			textbox_MAGc->Text = Convert::ToString(MAG);
		}
		else
		{
			// Displaying an error message if MAG is less than 0
			MessageBox::Show("MAG cannot be less than 0", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
}
	   //Mag text changed
Void CreateHero::textbox_MAGa_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	textbox_MAGc->Text = "";
	MAG = 0;
}
	   //PO +
Void CreateHero::pictureBox_plus15_Click(System::Object^ sender, System::EventArgs^ e) {
	// Checking if textbox_POa contains a valid number (not empty, integer between 1 and 9)
	if (textbox_POa->Text == "" || !Int32::TryParse(textbox_POa->Text, PO) || PO <= 0 || PO > 9)
	{
		// Displaying an error message if textbox_POa does not contain a correct value
		MessageBox::Show("Fill textbox with a correct number (1-9)", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	else if (textbox_POc->Text != "")
	{
		// Checking if textbox_POc is not empty
		PO = Convert::ToInt32(textbox_POc->Text);
		// Adding 1 to PO and updating textbox_POc if PO is less than 9
		if (PO < 9)
		{
			PO += 1;
			textbox_POc->Text = Convert::ToString(PO);
		}
		else
		{
			// Displaying an error message if PO exceeds 9
			MessageBox::Show("PO cannot exceed 9", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	else
	{
		// Updating PO based on textbox_POa
		PO = Convert::ToInt32(textbox_POa->Text);
		// Adding 1 to PO and updating textbox_POc if PO is less than 9
		if (PO < 9)
		{
			PO += 1;
			textbox_POc->Text = Convert::ToString(PO);
		}
		else
		{
			// Displaying an error message if PO exceeds 9
			MessageBox::Show("PO cannot exceed 9", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
}
	   //PO -
Void CreateHero::pictureBox_minus15_Click(System::Object^ sender, System::EventArgs^ e) {
	// Checking if textbox_POa contains a valid number (not empty, integer between 0 and 9)
	if (textbox_POa->Text == "" || !Int32::TryParse(textbox_POa->Text, PO) || PO < 0 || PO >= 10)
	{
		// Displaying an error message if textbox_POa does not contain a correct value
		MessageBox::Show("Fill textbox with a correct number (-1-9)", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	else if (textbox_POc->Text != "")
	{
		// Checking if textbox_POc is not empty
		PO = Convert::ToInt32(textbox_POc->Text);
		// Subtracting 1 from PO and updating textbox_POc if PO is greater than -1
		if (PO > 0)
		{
			PO -= 1;
			textbox_POc->Text = Convert::ToString(PO);
		}
		else
		{
			// Displaying an error message if PO is less than 0
			MessageBox::Show("PO cannot be less than 0", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	else
	{
		// Updating PO based on textbox_POa
		PO = Convert::ToInt32(textbox_POa->Text);
		// Subtracting 1 from PO and updating textbox_POc if PO is greater than 0
		if (PO > 0)
		{
			PO -= 1;
			textbox_POc->Text = Convert::ToString(PO);
		}
		else
		{
			// Displaying an error message if PO is less than 0
			MessageBox::Show("PO cannot be less than -1", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
}
	   //POa text changed
Void CreateHero::textbox_POa_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	textbox_POc->Text = "";
	PO = 0;
}
	   //PP +
Void CreateHero::pictureBox_plus16_Click(System::Object^ sender, System::EventArgs^ e) {
	// Checking if textbox_PPa contains a valid number (not empty, integer between -1 and 3)
	if (textbox_PPa->Text == "" || !Int32::TryParse(textbox_PPa->Text, PP) || PP < 0 || PP >= 4)
	{
		// Displaying an error message if textbox_PPa does not contain a correct value
		MessageBox::Show("Fill textbox with a correct number (0,-3)", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	else if (textbox_PPc->Text != "")
	{
		// Checking if textbox_PPc is not empty
		PP = Convert::ToInt32(textbox_PPc->Text);
		// Adding 1 to PP and updating textbox_PPc if PP is less than 3
		if (PP < 3)
		{
			PP += 1;
			textbox_PPc->Text = Convert::ToString(PP);
		}
		else
		{
			// Displaying an error message if PP exceeds 3
			MessageBox::Show("PP cannot exceed 3", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	else
	{
		// Updating PP based on textbox_PPa
		PP = Convert::ToInt32(textbox_PPa->Text);
		// Adding 1 to PP and updating textbox_PPc if PP is less than 3
		if (PP < 3)
		{
			PP += 1;
			textbox_PPc->Text = Convert::ToString(PP);
		}
		else
		{
			// Displaying an error message if PP exceeds 3
			MessageBox::Show("PP cannot exceed 3", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
}
	   //PP -
Void CreateHero::pictureBox_minus16_Click(System::Object^ sender, System::EventArgs^ e) {
	// Checking if textbox_PPa contains a valid number (not empty, integer between 0 and 3)
	if (textbox_PPa->Text == "" || !Int32::TryParse(textbox_PPa->Text, PP) || PP < 0 || PP >= 4)
	{
		// Displaying an error message if textbox_PPa does not contain a correct value
		MessageBox::Show("Fill textbox with a correct number (0,-3)", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	else if (textbox_PPc->Text != "")
	{
		// Checking if textbox_PPc is not empty
		PP = Convert::ToInt32(textbox_PPc->Text);
		// Subtracting 1 from PP and updating textbox_PPc if PP is greater than 0
		if (PP > 0)
		{
			PP -= 1;
			textbox_PPc->Text = Convert::ToString(PP);
		}
		else
		{
			// Displaying an error message if PP is less than 0
			MessageBox::Show("PP cannot be less than 0", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	else
	{
		// Updating PP based on textbox_PPa
		PP = Convert::ToInt32(textbox_PPa->Text);
		// Subtracting 1 from PP and updating textbox_PPc if PP is greater than 0
		if (PP > 0)
		{
			PP -= 1;
			textbox_PPc->Text = Convert::ToString(PP);
		}
		else
		{
			// Displaying an error message if PP is less than 0
			MessageBox::Show("PP cannot be less than 0", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
}
	   //PPa text changed
Void CreateHero::textbox_PPa_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	textbox_PPc->Text = "";
	PP = 0;
}
Void CreateHero::openToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	try
	{
		OpenFileDialog^ file_dialog = gcnew OpenFileDialog();
		file_dialog->Filter = "Text Files (*.txt)|*.txt|All Files (*.*)|*.*";
		file_dialog->Title = "Choose a file";

		System::Windows::Forms::DialogResult result = file_dialog->ShowDialog();

		if (result == System::Windows::Forms::DialogResult::OK)
		{
			String^ file_path = file_dialog->FileName;

			// create object to read from the file
			System::IO::StreamReader^ stream_reader = gcnew System::IO::StreamReader(file_path);

			String^ line;
			while ((line = stream_reader->ReadLine()) != nullptr)
			{
				// find the position of the colon
				int colon_position = line->IndexOf(':');

				// if colon character is found
				if (colon_position != -1)
				{
					String^ field_name = line->Substring(0, colon_position)->Trim();
					String^ field_value = line->Substring(colon_position + 1)->Trim();

					// assign field_value to corresponding textbox 
					//hero
					if (field_name == "Name")
						textbox_name->Text = field_value;
					else if (field_name == "Race")
						textbox_race->Text = field_value;
					else if (field_name == "Current Profession")
						textbox_cur_prof->Text = field_value;
					else if (field_name == "Previous Profession")
						textbox_prev_prof->Text = field_value;
					//hero desc
					else if (field_name == "Age")
						textbox_age->Text = field_value;
					else if (field_name == "Sex")
						textbox_sex->Text = field_value;
					else if (field_name == "Height")
						textbox_height->Text = field_value;
					else if (field_name == "Weight")
						textbox_weight->Text = field_value;
					else if (field_name == "Star Sign")
						textbox_star_sign->Text = field_value;
					else if (field_name == "Siblings")
						textbox_siblings->Text = field_value;
					else if (field_name == "Place of Birth")
						textbox_birthplace->Text = field_value;
					//hero main features
					else if (field_name == "Initial WW")
						textbox_WWa->Text = field_value;
					else if (field_name == "Current WW")
						textbox_WWc->Text = field_value;
					else if (field_name == "Initial US")
						textbox_USa->Text = field_value;
					else if (field_name == "Current US")
						textbox_USc->Text = field_value;
					else if (field_name == "Initial K")
						textbox_Ka->Text = field_value;
					else if (field_name == "Current K")
						textbox_Kc->Text = field_value;
					else if (field_name == "Initial Odp")
						textbox_ODPa->Text = field_value;
					else if (field_name == "Current Odp")
						textbox_ODPc->Text = field_value;
					else if (field_name == "Initial Zr")
						textbox_ZRa->Text = field_value;
					else if (field_name == "Current Zr")
						textbox_ZRc->Text = field_value;
					else if (field_name == "Initial Int")
						textbox_INTa->Text = field_value;
					else if (field_name == "Current Int")
						textbox_INTc->Text = field_value;
					else if (field_name == "Initial SW")
						textbox_SWa->Text = field_value;
					else if (field_name == "Current SW")
						textbox_SWc->Text = field_value;
					else if (field_name == "Initial Ogd")
						textbox_OGDa->Text = field_value;
					else if (field_name == "Current Ogd")
						textbox_OGDc->Text = field_value;
					//hero secondary features
					else if (field_name == "Initial A")
						textbox_Aa->Text = field_value;
					else if (field_name == "Current A")
						textbox_Ac->Text = field_value;
					else if (field_name == "Initial Zyw")
						textbox_ZYWa->Text = field_value;
					else if (field_name == "Current Zyw")
						textbox_ZYWc->Text = field_value;
					else if (field_name == "Initial S")
						textbox_Sa->Text = field_value;
					else if (field_name == "Current S")
						textbox_Sc->Text = field_value;
					else if (field_name == "Initial Wt")
						textbox_WTa->Text = field_value;
					else if (field_name == "Current Wt")
						textbox_SZc->Text = field_value;
					else if (field_name == "Initial Sz")
						textbox_ODPa->Text = field_value;
					else if (field_name == "Current Sz")
						textbox_SZc->Text = field_value;
					else if (field_name == "Initial Mag")
						textbox_MAGa->Text = field_value;
					else if (field_name == "Current Mag")
						textbox_MAGc->Text = field_value;
					else if (field_name == "Initial PO")
						textbox_POa->Text = field_value;
					else if (field_name == "Current PO")
						textbox_POc->Text = field_value;
					else if (field_name == "Initial PP")
						textbox_PPa->Text = field_value;
					else if (field_name == "Current PP")
						textbox_PPc->Text = field_value;
					//hero armor
					else if (field_name == "Armor head")
						tb_headarmor->Text = field_value;
					else if (field_name == "Armor body")
						tb_bodyarmor->Text = field_value;
					else if (field_name == "Right hand")
						tb_rightfarmor->Text = field_value;
					else if (field_name == "Left hand")
						tb_lefthandarmor->Text = field_value;
					else if (field_name == "Right Leg")
						tb_rightfarmor->Text = field_value;
					else if (field_name == "Left leg")
						tb_leftfootarrmor->Text = field_value;
				}
			}

			// close the strea
			stream_reader->Close();
		}
	}
	//catch errors
	catch (Exception^ er)
	{
		MessageBox::Show(er->Message, "ERROR", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
}









