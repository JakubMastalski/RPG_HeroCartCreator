#include "Windows.h"
#include "exception"
#include "CreateHero.h"
#include "Clock1.h"
#include "Rool.h"
#include "MyForm.h"

namespace RPG_HERO_CREATOR {
	MyForm::MyForm(void)
	{
		InitializeComponent();
		rool_form = gcnew Rool();
		hero_form = gcnew CreateHero();
		new_clock = gcnew Clock();
		panel_expanted = false;
		try {
			player = gcnew System::Media::SoundPlayer("C:\\Users\\USER\\Desktop\\Warhamer_UI\\snd\\main_music.wav");
			player->PlayLooping();
			isPlaying = true;
		}
		catch (System::Exception^ er) {
			MessageBox::Show(er->Message, "ERROR", MessageBoxButtons::OK, MessageBoxIcon::Error);
			isPlaying = false;
		}
		isPlaying = true;
		components = gcnew System::ComponentModel::Container();
	}
	MyForm::~MyForm()
	{
		if (components)
		{
			delete components;
		}
	}

	void MyForm::InitializeComponent(void)
	{
		this->components = (gcnew System::ComponentModel::Container());
		this->menu_picture1 = (gcnew System::Windows::Forms::PictureBox());
		this->main_label1 = (gcnew System::Windows::Forms::Label());
		this->main_button_options = (gcnew System::Windows::Forms::Button());
		this->main_panel1 = (gcnew System::Windows::Forms::Panel());
		this->create_hero_b = (gcnew System::Windows::Forms::Button());
		this->sound_b = (gcnew System::Windows::Forms::Button());
		this->main_exit_b = (gcnew System::Windows::Forms::Button());
		this->main_clock_b = (gcnew System::Windows::Forms::Button());
		this->main_role_b = (gcnew System::Windows::Forms::Button());
		this->main_create_b = (gcnew System::Windows::Forms::Button());
		this->menu_timer = (gcnew System::Windows::Forms::Timer(this->components));
		this->close_menu_timer = (gcnew System::Windows::Forms::Timer(this->components));
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->menu_picture1))->BeginInit();
		this->main_panel1->SuspendLayout();
		this->SuspendLayout();
		// 
		// menu_picture1
		// 
		this->menu_picture1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(5)),
			static_cast<System::Int32>(static_cast<System::Byte>(5)));
		this->menu_picture1->ImageLocation = L"C:\\Users\\USER\\Desktop\\Warhamer_UI\\img\\image_1.jpg";
		this->menu_picture1->Location = System::Drawing::Point(0, 0);
		this->menu_picture1->MaximumSize = System::Drawing::Size(950, 585);
		this->menu_picture1->MinimumSize = System::Drawing::Size(950, 585);
		this->menu_picture1->Name = L"menu_picture1";
		this->menu_picture1->Size = System::Drawing::Size(950, 585);
		this->menu_picture1->TabIndex = 0;
		this->menu_picture1->TabStop = false;
		this->menu_picture1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::menu_picture1_MouseDown);
		this->menu_picture1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::menu_picture1_MouseMove);
		this->menu_picture1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::menu_picture1_MouseUp);
		// 
		// main_label1
		// 
		this->main_label1->AutoSize = true;
		this->main_label1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		this->main_label1->Font = (gcnew System::Drawing::Font(L"Georgia", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->main_label1->ForeColor = System::Drawing::Color::Gainsboro;
		this->main_label1->Location = System::Drawing::Point(405, 48);
		this->main_label1->Name = L"main_label1";
		this->main_label1->Size = System::Drawing::Size(545, 46);
		this->main_label1->TabIndex = 1;
		this->main_label1->Text = L"Welcome in Word of RPG";
		// 
		// main_button_options
		// 
		this->main_button_options->BackColor = System::Drawing::Color::Black;
		this->main_button_options->Cursor = System::Windows::Forms::Cursors::Hand;
		this->main_button_options->FlatAppearance->BorderColor = System::Drawing::Color::Red;
		this->main_button_options->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)),
			static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)));
		this->main_button_options->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)),
			static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)));
		this->main_button_options->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		this->main_button_options->Font = (gcnew System::Drawing::Font(L"Georgia", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->main_button_options->ForeColor = System::Drawing::Color::Red;
		this->main_button_options->Location = System::Drawing::Point(506, 125);
		this->main_button_options->Margin = System::Windows::Forms::Padding(1);
		this->main_button_options->Name = L"main_button_options";
		this->main_button_options->Padding = System::Windows::Forms::Padding(1);
		this->main_button_options->Size = System::Drawing::Size(236, 58);
		this->main_button_options->TabIndex = 2;
		this->main_button_options->Text = L"Open Menu";
		this->main_button_options->UseVisualStyleBackColor = false;
		this->main_button_options->Click += gcnew System::EventHandler(this, &MyForm::main_button_options_Click);
		// 
		// main_panel1
		// 
		this->main_panel1->BackColor = System::Drawing::Color::Black;
		this->main_panel1->Controls->Add(this->create_hero_b);
		this->main_panel1->Controls->Add(this->sound_b);
		this->main_panel1->Controls->Add(this->main_exit_b);
		this->main_panel1->Controls->Add(this->main_clock_b);
		this->main_panel1->Controls->Add(this->main_role_b);
		this->main_panel1->Location = System::Drawing::Point(506, 204);
		this->main_panel1->Name = L"main_panel1";
		this->main_panel1->Size = System::Drawing::Size(237, 303);
		this->main_panel1->TabIndex = 3;
		// 
		// create_hero_b
		// 
		this->create_hero_b->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(15)),
			static_cast<System::Int32>(static_cast<System::Byte>(15)));
		this->create_hero_b->Cursor = System::Windows::Forms::Cursors::Hand;
		this->create_hero_b->FlatAppearance->BorderColor = System::Drawing::Color::Black;
		this->create_hero_b->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)),
			static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)));
		this->create_hero_b->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)),
			static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)));
		this->create_hero_b->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		this->create_hero_b->Font = (gcnew System::Drawing::Font(L"Georgia", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->create_hero_b->ForeColor = System::Drawing::Color::WhiteSmoke;
		this->create_hero_b->Location = System::Drawing::Point(0, 1);
		this->create_hero_b->Margin = System::Windows::Forms::Padding(1);
		this->create_hero_b->Name = L"create_hero_b";
		this->create_hero_b->Padding = System::Windows::Forms::Padding(1);
		this->create_hero_b->Size = System::Drawing::Size(236, 58);
		this->create_hero_b->TabIndex = 9;
		this->create_hero_b->Text = L"Create Hero";
		this->create_hero_b->UseVisualStyleBackColor = false;
		this->create_hero_b->Click += gcnew System::EventHandler(this, &MyForm::create_hero_b_Click);
		// 
		// sound_b
		// 
		this->sound_b->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(15)),
			static_cast<System::Int32>(static_cast<System::Byte>(15)));
		this->sound_b->Cursor = System::Windows::Forms::Cursors::Hand;
		this->sound_b->FlatAppearance->BorderColor = System::Drawing::Color::Black;
		this->sound_b->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)),
			static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)));
		this->sound_b->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)),
			static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)));
		this->sound_b->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		this->sound_b->Font = (gcnew System::Drawing::Font(L"Georgia", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->sound_b->ForeColor = System::Drawing::Color::WhiteSmoke;
		this->sound_b->Location = System::Drawing::Point(1, 180);
		this->sound_b->Margin = System::Windows::Forms::Padding(1);
		this->sound_b->Name = L"sound_b";
		this->sound_b->Padding = System::Windows::Forms::Padding(1);
		this->sound_b->Size = System::Drawing::Size(235, 58);
		this->sound_b->TabIndex = 8;
		this->sound_b->Text = L"Mute Sound";
		this->sound_b->UseVisualStyleBackColor = false;
		this->sound_b->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
		// 
		// main_exit_b
		// 
		this->main_exit_b->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(15)),
			static_cast<System::Int32>(static_cast<System::Byte>(15)));
		this->main_exit_b->Cursor = System::Windows::Forms::Cursors::Hand;
		this->main_exit_b->FlatAppearance->BorderColor = System::Drawing::Color::Black;
		this->main_exit_b->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)),
			static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)));
		this->main_exit_b->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)),
			static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)));
		this->main_exit_b->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		this->main_exit_b->Font = (gcnew System::Drawing::Font(L"Georgia", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->main_exit_b->ForeColor = System::Drawing::Color::WhiteSmoke;
		this->main_exit_b->Location = System::Drawing::Point(1, 240);
		this->main_exit_b->Margin = System::Windows::Forms::Padding(1);
		this->main_exit_b->Name = L"main_exit_b";
		this->main_exit_b->Padding = System::Windows::Forms::Padding(1);
		this->main_exit_b->Size = System::Drawing::Size(236, 58);
		this->main_exit_b->TabIndex = 7;
		this->main_exit_b->Text = L"Exit";
		this->main_exit_b->UseVisualStyleBackColor = false;
		this->main_exit_b->Click += gcnew System::EventHandler(this, &MyForm::main_exit_b_Click);
		// 
		// main_clock_b
		// 
		this->main_clock_b->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(15)),
			static_cast<System::Int32>(static_cast<System::Byte>(15)));
		this->main_clock_b->Cursor = System::Windows::Forms::Cursors::Hand;
		this->main_clock_b->FlatAppearance->BorderColor = System::Drawing::Color::Black;
		this->main_clock_b->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)),
			static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)));
		this->main_clock_b->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)),
			static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)));
		this->main_clock_b->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		this->main_clock_b->Font = (gcnew System::Drawing::Font(L"Georgia", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->main_clock_b->ForeColor = System::Drawing::Color::WhiteSmoke;
		this->main_clock_b->Location = System::Drawing::Point(0, 120);
		this->main_clock_b->Margin = System::Windows::Forms::Padding(1);
		this->main_clock_b->Name = L"main_clock_b";
		this->main_clock_b->Padding = System::Windows::Forms::Padding(1);
		this->main_clock_b->Size = System::Drawing::Size(236, 58);
		this->main_clock_b->TabIndex = 6;
		this->main_clock_b->Text = L"Clock";
		this->main_clock_b->UseVisualStyleBackColor = false;
		this->main_clock_b->Click += gcnew System::EventHandler(this, &MyForm::main_clock_b_Click);
		// 
		// main_role_b
		// 
		this->main_role_b->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(15)),
			static_cast<System::Int32>(static_cast<System::Byte>(15)));
		this->main_role_b->Cursor = System::Windows::Forms::Cursors::Hand;
		this->main_role_b->FlatAppearance->BorderColor = System::Drawing::Color::Black;
		this->main_role_b->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)),
			static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)));
		this->main_role_b->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)),
			static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)));
		this->main_role_b->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		this->main_role_b->Font = (gcnew System::Drawing::Font(L"Georgia", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->main_role_b->ForeColor = System::Drawing::Color::WhiteSmoke;
		this->main_role_b->Location = System::Drawing::Point(0, 60);
		this->main_role_b->Margin = System::Windows::Forms::Padding(1);
		this->main_role_b->Name = L"main_role_b";
		this->main_role_b->Padding = System::Windows::Forms::Padding(1);
		this->main_role_b->Size = System::Drawing::Size(236, 58);
		this->main_role_b->TabIndex = 5;
		this->main_role_b->Text = L"Rool the Dice";
		this->main_role_b->UseVisualStyleBackColor = false;
		this->main_role_b->Click += gcnew System::EventHandler(this, &MyForm::main_role_b_Click);
		// 
		// main_create_b
		// 
		this->main_create_b->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(10)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(10)));
		this->main_create_b->Cursor = System::Windows::Forms::Cursors::Hand;
		this->main_create_b->FlatAppearance->BorderColor = System::Drawing::Color::Black;
		this->main_create_b->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)),
			static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)));
		this->main_create_b->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)),
			static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)));
		this->main_create_b->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		this->main_create_b->Font = (gcnew System::Drawing::Font(L"Georgia", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->main_create_b->ForeColor = System::Drawing::Color::WhiteSmoke;
		this->main_create_b->Location = System::Drawing::Point(690, 204);
		this->main_create_b->Margin = System::Windows::Forms::Padding(1);
		this->main_create_b->Name = L"main_create_b";
		this->main_create_b->Padding = System::Windows::Forms::Padding(1);
		this->main_create_b->Size = System::Drawing::Size(236, 58);
		this->main_create_b->TabIndex = 4;
		this->main_create_b->Text = L"CREATE HERO";
		this->main_create_b->UseVisualStyleBackColor = false;
		// 
		// menu_timer
		// 
		this->menu_timer->Tick += gcnew System::EventHandler(this, &MyForm::menu_timer_Tick);
		// 
		// close_menu_timer
		// 
		this->close_menu_timer->Tick += gcnew System::EventHandler(this, &MyForm::close_menu_timer_Tick);
		// 
		// MyForm
		// 
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
		this->BackColor = System::Drawing::Color::Black;
		this->ClientSize = System::Drawing::Size(950, 585);
		this->Controls->Add(this->main_panel1);
		this->Controls->Add(this->main_button_options);
		this->Controls->Add(this->main_label1);
		this->Controls->Add(this->menu_picture1);
		this->Controls->Add(this->main_create_b);
		this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->ForeColor = System::Drawing::Color::White;
		this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
		this->MaximizeBox = false;
		this->MinimizeBox = false;
		this->Name = L"MyForm";
		this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
		this->Text = L"Main Menu";
		this->TransparencyKey = System::Drawing::Color::Transparent;
		this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->menu_picture1))->EndInit();
		this->main_panel1->ResumeLayout(false);
		this->ResumeLayout(false);
		this->PerformLayout();
	}
	//MY METHODS
	//show/close menu//enable menu_timer
Void MyForm::main_button_options_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!panel_expanted) //enable timer1 , disanable timer 2 change button text //timers START line 439
		{
			menu_timer->Enabled = true;
			close_menu_timer->Enabled = false;
			panel_expanted = true;
			main_button_options->Text = "Close Menu";

		}
		else //enable timer2 , disanable timer 1 change button text 
		{
			close_menu_timer->Enabled = true;
			menu_timer->Enabled = false;
			panel_expanted = false;
			main_button_options->Text = "Open Menu";
		}
	}
		   //close application
Void MyForm::main_exit_b_Click(System::Object^ sender, System::EventArgs^ e) {
		MyForm::Close();
	}
		   //dragging the form
Void MyForm::menu_picture1_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		dragging = true;
		offset.X = e->X;
		offset.Y = e->Y;
	}
Void MyForm::menu_picture1_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		//check whether able to move
		if (dragging)
		{
			// calculate new position of the form
			Point current_mouse_pos = PointToScreen(Point(e->X, e->Y));
			Point new_location = Point(current_mouse_pos.X - offset.X, current_mouse_pos.Y - offset.Y);
			// update the form's location
			this->Location = new_location;
		}
	}
Void MyForm::menu_picture1_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		//disable draging
		dragging = false;
	}

	//play music
Void MyForm::MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		//loop sound//catch errors
		main_panel1->Height = 0;
		try {
			player->PlayLooping();
			isPlaying = true;
		}
		catch (System::Exception^ er) {
			MessageBox::Show(er->Message, "ERROR", MessageBoxButtons::OK, MessageBoxIcon::Error);
			isPlaying = false;
		}
	}
     //mute sound//play
Void MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (isPlaying)
		{
			player->Stop();
			isPlaying = false;
			sound_b->Text = "Play Sound";
		}
		else
		{
			player->PlayLooping();
			isPlaying = true;
			sound_b->Text = "Mute Sound";
		}
	}
    //open rool dice form
Void MyForm::main_role_b_Click(System::Object^ sender, System::EventArgs^ e) {
		rool_form->Show();
		sound_b->Text = "Play sound";
		player->Stop();
		isPlaying = false;
	}

	//animation show menu//button START line 431
Void MyForm::menu_timer_Tick(System::Object^ sender, System::EventArgs^ e) {
	if (main_panel1->Height <= 320)
	{
		main_panel1->Height += interval;
	}
	else
	{
		menu_timer->Enabled = false;
		panel_expanted = true;
	}
}
    //close and open menu with tiemr animation
Void MyForm::close_menu_timer_Tick(System::Object^ sender, System::EventArgs^ e) {
			   if (main_panel1->Height > 0) {
				   main_panel1->Height -= interval;
			   }
			   else {
				   close_menu_timer->Enabled = false;
				   panel_expanted = false;
			   }
		   }
	//create hero form
Void MyForm::create_hero_b_Click(System::Object^ sender, System::EventArgs^ e) {
	hero_form->Show();
}
    //create timer form obj
Void MyForm:: main_clock_b_Click(System::Object^ sender, System::EventArgs^ e) {
	new_clock->Show();
}
}