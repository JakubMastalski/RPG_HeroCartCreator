#include "Rool.h"
#include <cstdlib>
#include <ctime>
#include <string>
#include <thread>
#include <chrono>
#include <iostream>

namespace RPG_HERO_CREATOR {

	Rool::Rool(void)
	{
		InitializeComponent();
		//
		//TODO: Add the constructor code here
		//
		components = gcnew System::ComponentModel::Container();
	}
	Rool::~Rool()
	{
		if (components)
		{
			delete components;
		}
	}

	void Rool::InitializeComponent()
	{
		this->components = (gcnew System::ComponentModel::Container());
		this->panel1 = (gcnew System::Windows::Forms::Panel());
		this->d100_dice = (gcnew System::Windows::Forms::Button());
		this->d20_dice = (gcnew System::Windows::Forms::Button());
		this->d12_dice = (gcnew System::Windows::Forms::Button());
		this->d10_dice = (gcnew System::Windows::Forms::Button());
		this->d8_dice = (gcnew System::Windows::Forms::Button());
		this->d6_dice = (gcnew System::Windows::Forms::Button());
		this->d4_dice = (gcnew System::Windows::Forms::Button());
		this->d2_dice = (gcnew System::Windows::Forms::Button());
		this->label_dice = (gcnew System::Windows::Forms::Label());
		this->rool_number = (gcnew System::Windows::Forms::ComboBox());
		this->dice_pb = (gcnew System::Windows::Forms::PictureBox());
		this->dice_timer = (gcnew System::Windows::Forms::Timer(this->components));
		this->rool_result = (gcnew System::Windows::Forms::Label());
		this->panel1->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dice_pb))->BeginInit();
		this->SuspendLayout();
		// 
		// panel1
		// 
		this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)),
			static_cast<System::Int32>(static_cast<System::Byte>(60)));
		this->panel1->Controls->Add(this->d100_dice);
		this->panel1->Controls->Add(this->d20_dice);
		this->panel1->Controls->Add(this->d12_dice);
		this->panel1->Controls->Add(this->d10_dice);
		this->panel1->Controls->Add(this->d8_dice);
		this->panel1->Controls->Add(this->d6_dice);
		this->panel1->Controls->Add(this->d4_dice);
		this->panel1->Controls->Add(this->d2_dice);
		this->panel1->Dock = System::Windows::Forms::DockStyle::Bottom;
		this->panel1->Location = System::Drawing::Point(0, 337);
		this->panel1->Name = L"panel1";
		this->panel1->Size = System::Drawing::Size(510, 143);
		this->panel1->TabIndex = 0;
		// 
		// d100_dice
		// 
		this->d100_dice->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(10)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(10)));
		this->d100_dice->Cursor = System::Windows::Forms::Cursors::Hand;
		this->d100_dice->FlatAppearance->BorderColor = System::Drawing::Color::DimGray;
		this->d100_dice->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)),
			static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)));
		this->d100_dice->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)),
			static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)));
		this->d100_dice->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		this->d100_dice->Font = (gcnew System::Drawing::Font(L"Impact", 14));
		this->d100_dice->ForeColor = System::Drawing::Color::WhiteSmoke;
		this->d100_dice->Location = System::Drawing::Point(342, 58);
		this->d100_dice->Margin = System::Windows::Forms::Padding(1);
		this->d100_dice->Name = L"d100_dice";
		this->d100_dice->Padding = System::Windows::Forms::Padding(1);
		this->d100_dice->Size = System::Drawing::Size(97, 56);
		this->d100_dice->TabIndex = 17;
		this->d100_dice->Text = L"D100";
		this->d100_dice->UseVisualStyleBackColor = false;
		this->d100_dice->Click += gcnew System::EventHandler(this, &Rool::d100_dice_Click);
		// 
		// d20_dice
		// 
		this->d20_dice->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(10)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(10)));
		this->d20_dice->Cursor = System::Windows::Forms::Cursors::Hand;
		this->d20_dice->FlatAppearance->BorderColor = System::Drawing::Color::DimGray;
		this->d20_dice->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)),
			static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)));
		this->d20_dice->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)),
			static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)));
		this->d20_dice->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		this->d20_dice->Font = (gcnew System::Drawing::Font(L"Impact", 14));
		this->d20_dice->ForeColor = System::Drawing::Color::WhiteSmoke;
		this->d20_dice->Location = System::Drawing::Point(252, 58);
		this->d20_dice->Margin = System::Windows::Forms::Padding(1);
		this->d20_dice->Name = L"d20_dice";
		this->d20_dice->Padding = System::Windows::Forms::Padding(1);
		this->d20_dice->Size = System::Drawing::Size(88, 56);
		this->d20_dice->TabIndex = 16;
		this->d20_dice->Text = L"D20";
		this->d20_dice->UseVisualStyleBackColor = false;
		this->d20_dice->Click += gcnew System::EventHandler(this, &Rool::d20_dice_Click);
		// 
		// d12_dice
		// 
		this->d12_dice->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(10)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(10)));
		this->d12_dice->Cursor = System::Windows::Forms::Cursors::Hand;
		this->d12_dice->FlatAppearance->BorderColor = System::Drawing::Color::DimGray;
		this->d12_dice->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)),
			static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)));
		this->d12_dice->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)),
			static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)));
		this->d12_dice->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		this->d12_dice->Font = (gcnew System::Drawing::Font(L"Impact", 14));
		this->d12_dice->ForeColor = System::Drawing::Color::WhiteSmoke;
		this->d12_dice->Location = System::Drawing::Point(155, 58);
		this->d12_dice->Margin = System::Windows::Forms::Padding(1);
		this->d12_dice->Name = L"d12_dice";
		this->d12_dice->Padding = System::Windows::Forms::Padding(1);
		this->d12_dice->Size = System::Drawing::Size(95, 56);
		this->d12_dice->TabIndex = 15;
		this->d12_dice->Text = L"D12";
		this->d12_dice->UseVisualStyleBackColor = false;
		this->d12_dice->Click += gcnew System::EventHandler(this, &Rool::d12_dice_Click);
		// 
		// d10_dice
		// 
		this->d10_dice->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(10)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(10)));
		this->d10_dice->Cursor = System::Windows::Forms::Cursors::Hand;
		this->d10_dice->FlatAppearance->BorderColor = System::Drawing::Color::DimGray;
		this->d10_dice->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)),
			static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)));
		this->d10_dice->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)),
			static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)));
		this->d10_dice->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		this->d10_dice->Font = (gcnew System::Drawing::Font(L"Impact", 14));
		this->d10_dice->ForeColor = System::Drawing::Color::WhiteSmoke;
		this->d10_dice->Location = System::Drawing::Point(58, 58);
		this->d10_dice->Margin = System::Windows::Forms::Padding(1);
		this->d10_dice->Name = L"d10_dice";
		this->d10_dice->Padding = System::Windows::Forms::Padding(1);
		this->d10_dice->Size = System::Drawing::Size(95, 56);
		this->d10_dice->TabIndex = 14;
		this->d10_dice->Text = L"D10";
		this->d10_dice->UseVisualStyleBackColor = false;
		this->d10_dice->Click += gcnew System::EventHandler(this, &Rool::d10_dice_Click);
		// 
		// d8_dice
		// 
		this->d8_dice->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(10)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(10)));
		this->d8_dice->Cursor = System::Windows::Forms::Cursors::Hand;
		this->d8_dice->FlatAppearance->BorderColor = System::Drawing::Color::DimGray;
		this->d8_dice->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)),
			static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)));
		this->d8_dice->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)),
			static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)));
		this->d8_dice->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		this->d8_dice->Font = (gcnew System::Drawing::Font(L"Impact", 14));
		this->d8_dice->ForeColor = System::Drawing::Color::WhiteSmoke;
		this->d8_dice->Location = System::Drawing::Point(342, 0);
		this->d8_dice->Margin = System::Windows::Forms::Padding(1);
		this->d8_dice->Name = L"d8_dice";
		this->d8_dice->Padding = System::Windows::Forms::Padding(1);
		this->d8_dice->Size = System::Drawing::Size(97, 56);
		this->d8_dice->TabIndex = 13;
		this->d8_dice->Text = L"D8";
		this->d8_dice->UseVisualStyleBackColor = false;
		this->d8_dice->Click += gcnew System::EventHandler(this, &Rool::d8_dice_Click);
		// 
		// d6_dice
		// 
		this->d6_dice->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(10)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(10)));
		this->d6_dice->Cursor = System::Windows::Forms::Cursors::Hand;
		this->d6_dice->FlatAppearance->BorderColor = System::Drawing::Color::DimGray;
		this->d6_dice->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)),
			static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)));
		this->d6_dice->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)),
			static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)));
		this->d6_dice->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		this->d6_dice->Font = (gcnew System::Drawing::Font(L"Impact", 14));
		this->d6_dice->ForeColor = System::Drawing::Color::WhiteSmoke;
		this->d6_dice->Location = System::Drawing::Point(252, 0);
		this->d6_dice->Margin = System::Windows::Forms::Padding(1);
		this->d6_dice->Name = L"d6_dice";
		this->d6_dice->Padding = System::Windows::Forms::Padding(1);
		this->d6_dice->Size = System::Drawing::Size(88, 56);
		this->d6_dice->TabIndex = 12;
		this->d6_dice->Text = L"D6";
		this->d6_dice->UseVisualStyleBackColor = false;
		this->d6_dice->Click += gcnew System::EventHandler(this, &Rool::d6_dice_Click);
		// 
		// d4_dice
		// 
		this->d4_dice->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(10)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(10)));
		this->d4_dice->Cursor = System::Windows::Forms::Cursors::Hand;
		this->d4_dice->FlatAppearance->BorderColor = System::Drawing::Color::DimGray;
		this->d4_dice->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)),
			static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)));
		this->d4_dice->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)),
			static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)));
		this->d4_dice->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		this->d4_dice->Font = (gcnew System::Drawing::Font(L"Impact", 14));
		this->d4_dice->ForeColor = System::Drawing::Color::WhiteSmoke;
		this->d4_dice->Location = System::Drawing::Point(155, 0);
		this->d4_dice->Margin = System::Windows::Forms::Padding(1);
		this->d4_dice->Name = L"d4_dice";
		this->d4_dice->Padding = System::Windows::Forms::Padding(1);
		this->d4_dice->Size = System::Drawing::Size(95, 56);
		this->d4_dice->TabIndex = 11;
		this->d4_dice->Text = L"D4";
		this->d4_dice->UseVisualStyleBackColor = false;
		this->d4_dice->Click += gcnew System::EventHandler(this, &Rool::d4_dice_Click);
		// 
		// d2_dice
		// 
		this->d2_dice->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(10)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(10)));
		this->d2_dice->Cursor = System::Windows::Forms::Cursors::Hand;
		this->d2_dice->FlatAppearance->BorderColor = System::Drawing::Color::DimGray;
		this->d2_dice->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)),
			static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)));
		this->d2_dice->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)),
			static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)));
		this->d2_dice->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		this->d2_dice->Font = (gcnew System::Drawing::Font(L"Impact", 14));
		this->d2_dice->ForeColor = System::Drawing::Color::White;
		this->d2_dice->Location = System::Drawing::Point(58, 0);
		this->d2_dice->Margin = System::Windows::Forms::Padding(1);
		this->d2_dice->Name = L"d2_dice";
		this->d2_dice->Padding = System::Windows::Forms::Padding(1);
		this->d2_dice->Size = System::Drawing::Size(95, 56);
		this->d2_dice->TabIndex = 10;
		this->d2_dice->Text = L"D2";
		this->d2_dice->UseVisualStyleBackColor = false;
		this->d2_dice->Click += gcnew System::EventHandler(this, &Rool::d2_dice_Click);
		// 
		// label_dice
		// 
		this->label_dice->AutoSize = true;
		this->label_dice->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
		this->label_dice->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
		this->label_dice->ForeColor = System::Drawing::Color::Gainsboro;
		this->label_dice->Location = System::Drawing::Point(4, 8);
		this->label_dice->Name = L"label_dice";
		this->label_dice->Size = System::Drawing::Size(348, 41);
		this->label_dice->TabIndex = 2;
		this->label_dice->Text = L"CHOOSE A NUMBER OF\r\n";
		// 
		// rool_number
		// 
		this->rool_number->BackColor = System::Drawing::SystemColors::Menu;
		this->rool_number->Cursor = System::Windows::Forms::Cursors::Hand;
		this->rool_number->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.8F));
		this->rool_number->ForeColor = System::Drawing::Color::Black;
		this->rool_number->FormattingEnabled = true;
		this->rool_number->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"ONE", L"TWO" });
		this->rool_number->Location = System::Drawing::Point(375, 16);
		this->rool_number->Name = L"rool_number";
		this->rool_number->Size = System::Drawing::Size(129, 33);
		this->rool_number->TabIndex = 3;
		this->rool_number->Text = L"DICE";
		this->rool_number->SelectedIndexChanged += gcnew System::EventHandler(this, &Rool::rool_number_SelectedIndexChanged);
		// 
		// dice_pb
		// 
		this->dice_pb->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
			| System::Windows::Forms::AnchorStyles::Left)
			| System::Windows::Forms::AnchorStyles::Right));
		this->dice_pb->BackColor = System::Drawing::Color::Transparent;
		this->dice_pb->Enabled = false;
		this->dice_pb->ImageLocation = L"C:\\Users\\USER\\Desktop\\rooldice.jpg";
		this->dice_pb->Location = System::Drawing::Point(120, 52);
		this->dice_pb->Name = L"dice_pb";
		this->dice_pb->Size = System::Drawing::Size(220, 220);
		this->dice_pb->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
		this->dice_pb->TabIndex = 4;
		this->dice_pb->TabStop = false;
		this->dice_pb->Visible = false;
		// 
		// dice_timer
		// 
		this->dice_timer->Interval = 300;
		this->dice_timer->Tick += gcnew System::EventHandler(this, &Rool::dice_timer_Tick);
		// 
		// rool_result
		// 
		this->rool_result->AutoSize = true;
		this->rool_result->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
		this->rool_result->Font = (gcnew System::Drawing::Font(L"Segoe UI", 48, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
		this->rool_result->ForeColor = System::Drawing::Color::Gainsboro;
		this->rool_result->Location = System::Drawing::Point(156, 129);
		this->rool_result->Name = L"rool_result";
		this->rool_result->Size = System::Drawing::Size(137, 106);
		this->rool_result->TabIndex = 5;
		this->rool_result->Text = L"12";
		this->rool_result->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		// 
		// Rool
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(113)), static_cast<System::Int32>(static_cast<System::Byte>(113)),
			static_cast<System::Int32>(static_cast<System::Byte>(113)));
		this->ClientSize = System::Drawing::Size(510, 480);
		this->Controls->Add(this->dice_pb);
		this->Controls->Add(this->rool_result);
		this->Controls->Add(this->rool_number);
		this->Controls->Add(this->label_dice);
		this->Controls->Add(this->panel1);
		this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
		this->MaximizeBox = false;
		this->MaximumSize = System::Drawing::Size(528, 527);
		this->MinimizeBox = false;
		this->MinimumSize = System::Drawing::Size(528, 527);
		this->Name = L"Rool";
		this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
		this->Text = L"Rool";
		this->Load += gcnew System::EventHandler(this, &Rool::Rool_Load);
		this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Rool::Rool_MouseDown);
		this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Rool::Rool_MouseMove);
		this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Rool::Rool_MouseUp);
		this->panel1->ResumeLayout(false);
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dice_pb))->EndInit();
		this->ResumeLayout(false);
		this->PerformLayout();
	}
	void Rool:: new_color()
	{
		int last_color_index = -1;
		int rand;
		do {
			rand = random_font->Next(1, 11); // RANDOM COLOR 1..10
		} while (rand == last_color_index); // DO UNTIL COLOR IS DIFRENT

		last_color_index = rand; // LAST USED INDEX

		switch (rand)
		{
		case 1:
			rool_result->ForeColor = System::Drawing::Color::DarkGreen;
			break;
		case 2:
			rool_result->ForeColor = System::Drawing::Color::DarkBlue;
			break;
		case 3:
			rool_result->ForeColor = System::Drawing::Color::DarkCyan;
			break;
		case 4:
			rool_result->ForeColor = System::Drawing::Color::DarkGoldenrod;
			break;
		case 5:
			rool_result->ForeColor = System::Drawing::Color::DarkGray;
			break;
		case 6:
			rool_result->ForeColor = System::Drawing::Color::DarkKhaki;
			break;
		case 7:
			rool_result->ForeColor = System::Drawing::Color::DarkMagenta;
			break;
		case 8:
			rool_result->ForeColor = System::Drawing::Color::DarkOliveGreen;
			break;
		case 9:
			rool_result->ForeColor = System::Drawing::Color::DarkOrange;
			break;
		case 10:
			rool_result->ForeColor = System::Drawing::Color::DarkOrchid;
			break;
		default:
			rool_result->ForeColor = System::Drawing::Color::DarkRed;
			break;
		}
	}
	Void Rool::d2_dice_Click(System::Object^ sender, System::EventArgs^ e) {
		//FONT CHANGE
		font_change();
		d2_dice->ForeColor = System::Drawing::Color::Gold;
		//MAKE DICE INVISIBLE
		dice_pb->Visible = true;
		dice_timer->Start();
		//PLAY SOUND
		try
		{
			player_rool->Play();
		}
		catch (Exception^ e)
		{
			MessageBox::Show(e->Message, "ERROR", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		//FREZE PROGRAM 

		//SWITCH
		switch (player_choice)
		{
		case 1:
		{
			dice_result_variable = random_number->Next(2);
			if (dice_result_variable == 1)
			{


				new_color();
				rool_result->Text = "H";

			}
			else
			{
				new_color();
				rool_result->Text = "T";
			}
			break;
			dice_timer->Stop();
			//2 NUMBERS
		case 2:
		{
			dice_result_variable = random_number->Next(2);
			dice_result_variable2 = random_number->Next(2);

			if (dice_result_variable == 1 && dice_result_variable2 == 1)
			{
				new_color();
				rool_result->Text = "H H";
			}
			else if (dice_result_variable == 1 && dice_result_variable2 == 0)
			{
				new_color();
				rool_result->Text = "H T";
			}
			else if (dice_result_variable == 0 && dice_result_variable2 == 1)
			{
				new_color();
				rool_result->Text = "T H";
			}
			else
			{
				new_color();
				rool_result->Text = "T T";
			}
			break;
			//DEFAULT
		default:
			dice_result_variable = random_number->Next(2);
			if (dice_result_variable == 1)
			{
				new_color();
				rool_result->Text = "H";

			}
			else
			{
				new_color();
				rool_result->Text = "T";
			}
			break;
		}
		}
		}
	}

	Void Rool::d4_dice_Click(System::Object^ sender, System::EventArgs^ e) {
		//FONT CHANGE
		font_change();
		d4_dice->ForeColor = System::Drawing::Color::Gold;
		//MAKE DICE INVISIBLE
		dice_pb->Visible = true;
		dice_timer->Start();
		//PLAY SOUND
		try
		{
			player_rool->Play();
		}
		catch (Exception^ e)
		{
			MessageBox::Show(e->Message, "ERROR", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		//SWITCH
		switch (player_choice)
		{
		case 1:
		{
			new_color();
			dice_result_variable = random_number->Next(1, 5);
			rool_result->Text = dice_result_variable.ToString();
			dice_result_variable = 0;
			dice_result_variable = 0;
			break;
		}
		//2 NUMBERS
		case 2:
			new_color();
			dice_result_variable = random_number->Next(1, 5);
			dice_result_variable2 = random_number->Next(1, 5);
			rool_result->Text = dice_result_variable.ToString() + " " + dice_result_variable2.ToString();
			dice_result_variable = 0;
			dice_result_variable2 = 0;
			break;
			//DEFAULT
		default:
		{
			new_color();
			dice_result_variable = random_number->Next(1, 5);
			rool_result->Text = dice_result_variable.ToString();
			dice_result_variable = 0;
			dice_result_variable = 0;
			break;
		}
		}
	}

	Void Rool::Rool_Load(System::Object^ sender, System::EventArgs^ e) {
		rool_result->Text = "";
	}
	Void Rool::d6_dice_Click(System::Object^ sender, System::EventArgs^ e) {
		//FONT CHANGE
		font_change();
		d6_dice->ForeColor = System::Drawing::Color::Gold;
		//MAKE DICE INVISIBLE
		dice_pb->Visible = true;
		dice_timer->Start();
		//PLAY SOUND
		try
		{
			player_rool->Play();
		}
		catch (Exception^ e)
		{
			MessageBox::Show(e->Message, "ERROR", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		//SWITCH
		switch (player_choice)
		{
		case 1:
		{
			new_color();
			dice_result_variable = random_number->Next(1, 7);
			rool_result->Text = dice_result_variable.ToString();
			dice_result_variable = 0;
			dice_result_variable = 0;
			break;
		}
		//2 NUMBERS
		case 2:
			new_color();
			dice_result_variable = random_number->Next(1, 7);
			dice_result_variable2 = random_number->Next(1, 7);
			rool_result->Text = dice_result_variable.ToString() + " " + dice_result_variable2.ToString();
			dice_result_variable = 0;
			dice_result_variable2 = 0;
			break;
			//DEFAULT
		default:
		{
			new_color();
			dice_result_variable = random_number->Next(1, 7);
			rool_result->Text = dice_result_variable.ToString();
			dice_result_variable = 0;
			dice_result_variable = 0;
			break;
		}
		}
	}
	//D8 DICE 1..8 NUMBERS
Void Rool:: d8_dice_Click(System::Object^ sender, System::EventArgs^ e) {
	;
	//FONT CHANGE
	font_change();
	d8_dice->ForeColor = System::Drawing::Color::Gold;
	//MAKE DICE INVISIBLE
	dice_pb->Visible = true;
	dice_timer->Start();
	//PLAY SOUND
	try
	{
		player_rool->Play();
	}
	catch (Exception^ e)
	{
		MessageBox::Show(e->Message, "ERROR", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	//SWITCH
	switch (player_choice)
	{
	case 1:
	{
		new_color();
		dice_result_variable = random_number->Next(1, 9);
		rool_result->Text = dice_result_variable.ToString();
		dice_result_variable = 0;
		dice_result_variable = 0;
		break;
	}
	//2 NUMBERS
	case 2:
		new_color();
		dice_result_variable = random_number->Next(1, 9);
		dice_result_variable2 = random_number->Next(1, 9);
		rool_result->Text = dice_result_variable.ToString() + " " + dice_result_variable2.ToString();
		dice_result_variable = 0;
		dice_result_variable2 = 0;
		break;
		//DEFAULT
	default:
	{
		new_color();
		dice_result_variable = random_number->Next(1, 9);
		rool_result->Text = dice_result_variable.ToString();
		dice_result_variable = 0;
		dice_result_variable = 0;
		break;
	}
	}

}
	   //D10 DICE 1..10 NUMBERS
Void Rool::d10_dice_Click(System::Object^ sender, System::EventArgs^ e) {
	//FONT CHANGE
	font_change();
	d10_dice->ForeColor = System::Drawing::Color::Gold;
	//MAKE DICE INVISIBLE
	dice_pb->Visible = true;
	dice_timer->Start();
	//PLAY SOUND
	try
	{
		player_rool->Play();
	}
	catch (Exception^ e)
	{
		MessageBox::Show(e->Message, "ERROR", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	//SWITCH
	switch (player_choice)
	{
	case 1:
	{
		new_color();
		dice_result_variable = random_number->Next(1, 11);
		rool_result->Text = dice_result_variable.ToString();
		dice_result_variable = 0;
		dice_result_variable = 0;
		break;
	}
	//2 NUMBERS
	case 2:
		new_color();
		dice_result_variable = random_number->Next(1, 11);
		dice_result_variable2 = random_number->Next(1, 11);
		rool_result->Text = dice_result_variable.ToString() + " " + dice_result_variable2.ToString();
		dice_result_variable = 0;
		dice_result_variable2 = 0;
		break;
		//DEFAULT
	default:
	{
		new_color();
		dice_result_variable = random_number->Next(1, 11);
		rool_result->Text = dice_result_variable.ToString();
		dice_result_variable = 0;
		dice_result_variable = 0;
		break;
	}
	}
}
	   //D12 DICE 1..12 NUMBERS  
Void Rool::d12_dice_Click(System::Object^ sender, System::EventArgs^ e) {
	//FONT CHANGE
	font_change();
	d12_dice->ForeColor = System::Drawing::Color::Gold;
	//MAKE DICE INVISIBLE
	dice_pb->Visible = true;
	dice_timer->Start();
	//PLAY SOUND
	try
	{
		player_rool->Play();
	}
	catch (Exception^ e)
	{
		MessageBox::Show(e->Message, "ERROR", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	//SWITCH
	switch (player_choice)
	{
	case 1:
	{
		new_color();
		dice_result_variable = random_number->Next(1, 13);
		rool_result->Text = dice_result_variable.ToString();
		dice_result_variable = 0;
		dice_result_variable = 0;
		break;
	}
	//2 NUMBERS
	case 2:
		new_color();
		dice_result_variable = random_number->Next(1, 13);
		dice_result_variable2 = random_number->Next(1, 13);
		rool_result->Text = dice_result_variable.ToString() + " " + dice_result_variable2.ToString();
		dice_result_variable = 0;
		dice_result_variable2 = 0;
		break;
		//DEFAULT
	default:
	{
		new_color();
		dice_result_variable = random_number->Next(1, 13);
		rool_result->Text = dice_result_variable.ToString();
		dice_result_variable = 0;
		dice_result_variable = 0;
		break;
	}
	}
}
	   //D20 DICE 1..20 NUMBERS 
Void Rool::d20_dice_Click(System::Object^ sender, System::EventArgs^ e) {
	//FONT CHANGE
	font_change();
	d20_dice->ForeColor = System::Drawing::Color::Gold;
	//MAKE DICE INVISIBLE
	dice_pb->Visible = true;
	dice_timer->Start();
	//PLAY SOUND
	try
	{
		player_rool->Play();
	}
	catch (Exception^ e)
	{
		MessageBox::Show(e->Message, "ERROR", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	//SWITCH
	switch (player_choice)
	{
	case 1:
	{
		new_color();
		dice_result_variable = random_number->Next(1, 21);
		rool_result->Text = dice_result_variable.ToString();
		dice_result_variable = 0;
		dice_result_variable = 0;
		break;
	}
	//2 NUMBERS
	case 2:
		new_color();
		dice_result_variable = random_number->Next(1, 21);
		dice_result_variable2 = random_number->Next(1, 21);
		rool_result->Text = dice_result_variable.ToString() + " " + dice_result_variable2.ToString();
		dice_result_variable = 0;
		dice_result_variable2 = 0;
		break;
		//DEFAULT
	default:
	{
		new_color();
		dice_result_variable = random_number->Next(1, 21);
		rool_result->Text = dice_result_variable.ToString();
		dice_result_variable = 0;
		dice_result_variable = 0;
		break;
	}
	}
}
	   //D100 DICE 1..100 NUMBERS 
Void Rool::d100_dice_Click(System::Object^ sender, System::EventArgs^ e) {
	//FONT CHANGE
	font_change();
	d100_dice->ForeColor = System::Drawing::Color::Gold;
	//MAKE DICE INVISIBLE
	dice_pb->Visible = true;
	dice_timer->Start();
	//PLAY SOUND
	try
	{
		player_rool->Play();
	}
	catch (Exception^ e)
	{
		MessageBox::Show(e->Message, "ERROR", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	//SWITCH
	switch (player_choice)
	{
	case 1:
	{
		new_color();
		dice_result_variable = random_number->Next(1, 101);
		rool_result->Text = dice_result_variable.ToString();
		dice_result_variable = 0;
		dice_result_variable = 0;
		break;
	}
	//2 NUMBERS
	case 2:
		new_color();
		dice_result_variable = random_number->Next(1, 101);
		dice_result_variable2 = random_number->Next(1, 101);
		rool_result->Text = dice_result_variable.ToString() + " " + dice_result_variable2.ToString();
		dice_result_variable = 0;
		dice_result_variable2 = 0;
		break;
		//DEFAULT
	default:
	{
		new_color();
		dice_result_variable = random_number->Next(1, 101);
		rool_result->Text = dice_result_variable.ToString();
		dice_result_variable = 0;
		dice_result_variable = 0;
		break;
	}
	}
}
	   //draging form
	   bool draging;
	   Point offset;
Void Rool::Rool_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	//enable draging get mouse position
	draging = true;
	offset.X = e->X;
	offset.Y = e->Y;
}
Void Rool::Rool_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	//check wheter able to move
	if (draging)
	{
		//calculate location
		Point current_mouse_pos = PointToScreen(Point(e->X, e->Y));
		Location = Point(current_mouse_pos.X - offset.X, current_mouse_pos.Y - offset.Y);
	}
}
Void Rool::Rool_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	//disable draging
	draging = false;
}

Void Rool::rool_number_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	//set dice number
	if (rool_number->Text == "ONE" || rool_number->Text == "DICE")
	{
		player_choice = 1;

	}
	else if (rool_number->Text == "TWO")
	{
		player_choice = 2;
	}
}
	   //draging by keeping rool result
	   bool draging2;
	   Point offset2;
Void Rool::rool_result_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	//enable draging track mouse pos
	draging2 = true;
	offset2.X = e->X;
	offset2.Y = e->Y;
}
Void Rool::rool_result_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	//get current pos
	if (draging2)
	{
		Point currentlocation2 = PointToScreen(Point(e->X, e->Y));
		Location = Point(currentlocation2.X - offset2.X, currentlocation2.Y - offset2.Y);
	}

}
Void Rool::rool_result_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	//disable draging
	draging2 = false;
}
	   void Rool::wait_thread()
	   {
		   std::this_thread::sleep_for(std::chrono::seconds(1));
	   }
	   //timer 
Void Rool::dice_timer_Tick(System::Object^ sender, System::EventArgs^ e) {
	wait_thread();
	dice_pb->Visible = false;
	dice_timer->Stop();
}
	   //button font change
	   void Rool::font_change()
	   {
		   // D2_dice button
		   d2_dice->ForeColor = System::Drawing::Color::White;

		   // D4_dice button
		   d4_dice->ForeColor = System::Drawing::Color::White;

		   // D6_dice button
		   d6_dice->ForeColor = System::Drawing::Color::White;

		   // D8_dice button
		   d8_dice->ForeColor = System::Drawing::Color::White;

		   // D10_dice button
		   d10_dice->ForeColor = System::Drawing::Color::White;

		   // D12_dice button
		   d12_dice->ForeColor = System::Drawing::Color::White;

		   // D20_dice button
		   d20_dice->ForeColor = System::Drawing::Color::White;

		   // D100_dice button
		   d100_dice->ForeColor = System::Drawing::Color::White;
	   }
}

