#include "Clock1.h"

namespace RPG_HERO_CREATOR {

    Clock::Clock(void)
    {
        InitializeComponent();
        //
        //TODO: Add the constructor code here
        //
        components = gcnew System::ComponentModel::Container();
    }

    Clock::~Clock()
    {
        if (components)
        {
            delete components;
        }
    }

    void Clock::InitializeComponent()
    {
        this->components = (gcnew System::ComponentModel::Container());
        this->panel_clock_image = (gcnew System::Windows::Forms::Panel());
        this->clock_image = (gcnew System::Windows::Forms::PictureBox());
        this->reset_b = (gcnew System::Windows::Forms::Button());
        this->start_stop_b = (gcnew System::Windows::Forms::Button());
        this->panel2 = (gcnew System::Windows::Forms::Panel());
        this->time_label = (gcnew System::Windows::Forms::Label());
        this->timer_clock = (gcnew System::Windows::Forms::Timer(this->components));
        this->panel_clock_image->SuspendLayout();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->clock_image))->BeginInit();
        this->panel2->SuspendLayout();
        this->SuspendLayout();
        // 
        // panel_clock_image
        // 
        this->panel_clock_image->Controls->Add(this->clock_image);
        this->panel_clock_image->Dock = System::Windows::Forms::DockStyle::Left;
        this->panel_clock_image->Location = System::Drawing::Point(0, 0);
        this->panel_clock_image->Name = L"panel_clock_image";
        this->panel_clock_image->Size = System::Drawing::Size(400, 553);
        this->panel_clock_image->TabIndex = 0;
        // 
        // clock_image
        // 
        this->clock_image->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
            | System::Windows::Forms::AnchorStyles::Left)
            | System::Windows::Forms::AnchorStyles::Right));
        this->clock_image->ImageLocation = L"C:\\Users\\USER\\Desktop\\Warhamer_UI\\img\\klepsydra.jpg";
        this->clock_image->Location = System::Drawing::Point(0, 0);
        this->clock_image->Name = L"clock_image";
        this->clock_image->Size = System::Drawing::Size(275, 478);
        this->clock_image->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
        this->clock_image->TabIndex = 0;
        this->clock_image->TabStop = false;
        // 
        // reset_b
        // 
        this->reset_b->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)),
            static_cast<System::Int32>(static_cast<System::Byte>(25)));
        this->reset_b->Cursor = System::Windows::Forms::Cursors::Hand;
        this->reset_b->FlatAppearance->BorderColor = System::Drawing::Color::Black;
        this->reset_b->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)),
            static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)));
        this->reset_b->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)),
            static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)));
        this->reset_b->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->reset_b->Font = (gcnew System::Drawing::Font(L"Georgia", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(238)));
        this->reset_b->ForeColor = System::Drawing::Color::WhiteSmoke;
        this->reset_b->Location = System::Drawing::Point(0, 23);
        this->reset_b->Margin = System::Windows::Forms::Padding(1);
        this->reset_b->Name = L"reset_b";
        this->reset_b->Padding = System::Windows::Forms::Padding(1);
        this->reset_b->Size = System::Drawing::Size(191, 58);
        this->reset_b->TabIndex = 7;
        this->reset_b->Text = L"Reset";
        this->reset_b->UseVisualStyleBackColor = false;
        this->reset_b->Click += gcnew System::EventHandler(this, &Clock::reset_b_Click);
        // 
        // start_stop_b
        // 
        this->start_stop_b->BackColor = System::Drawing::Color::DarkGreen;
        this->start_stop_b->Cursor = System::Windows::Forms::Cursors::Hand;
        this->start_stop_b->FlatAppearance->BorderColor = System::Drawing::Color::Black;
        this->start_stop_b->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)),
            static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)));
        this->start_stop_b->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)),
            static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)));
        this->start_stop_b->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->start_stop_b->Font = (gcnew System::Drawing::Font(L"Georgia", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(238)));
        this->start_stop_b->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(250)),
            static_cast<System::Int32>(static_cast<System::Byte>(0)));
        this->start_stop_b->Location = System::Drawing::Point(193, 23);
        this->start_stop_b->Margin = System::Windows::Forms::Padding(1);
        this->start_stop_b->Name = L"start_stop_b";
        this->start_stop_b->Padding = System::Windows::Forms::Padding(1);
        this->start_stop_b->Size = System::Drawing::Size(191, 58);
        this->start_stop_b->TabIndex = 8;
        this->start_stop_b->Text = L"Start";
        this->start_stop_b->UseVisualStyleBackColor = false;
        this->start_stop_b->Click += gcnew System::EventHandler(this, &Clock::start_stop_b_Click);
        // 
        // panel2
        // 
        this->panel2->BackColor = System::Drawing::Color::DarkGray;
        this->panel2->Controls->Add(this->reset_b);
        this->panel2->Controls->Add(this->start_stop_b);
        this->panel2->Dock = System::Windows::Forms::DockStyle::Bottom;
        this->panel2->Location = System::Drawing::Point(400, 453);
        this->panel2->Name = L"panel2";
        this->panel2->Size = System::Drawing::Size(402, 100);
        this->panel2->TabIndex = 9;
        // 
        // time_label
        // 
        this->time_label->AutoSize = true;
        this->time_label->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->time_label->Font = (gcnew System::Drawing::Font(L"Segoe UI Black", 49.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(238)));
        this->time_label->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)),
            static_cast<System::Int32>(static_cast<System::Byte>(20)));
        this->time_label->Location = System::Drawing::Point(381, 202);
        this->time_label->Name = L"time_label";
        this->time_label->Size = System::Drawing::Size(401, 110);
        this->time_label->TabIndex = 10;
        this->time_label->Text = L"00:00:00";
        // 
        // timer_clock
        // 
        this->timer_clock->Interval = 1;
        this->timer_clock->Tick += gcnew System::EventHandler(this, &Clock::timer_clock_Tick);
        // 
        // Clock
        // 
        this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->BackColor = System::Drawing::SystemColors::AppWorkspace;
        this->ClientSize = System::Drawing::Size(802, 553);
        this->Controls->Add(this->time_label);
        this->Controls->Add(this->panel2);
        this->Controls->Add(this->panel_clock_image);
        this->MaximizeBox = false;
        this->MinimizeBox = false;
        this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
        this->MaximumSize = System::Drawing::Size(820, 600);
        this->MinimumSize = System::Drawing::Size(820, 600);
        this->Name = L"Clock";
        this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
        this->Text = L"Clock";
        this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Clock::Clock_MouseDown);
        this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Clock::Clock_MouseMove);
        this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Clock::Clock_MouseUp);
        this->panel_clock_image->ResumeLayout(false);
        this->panel_clock_image->PerformLayout();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->clock_image))->EndInit();
        this->panel2->ResumeLayout(false);
        this->ResumeLayout(false);
        this->PerformLayout();
    }

    void Clock::reset_b_Click(System::Object^ sender, System::EventArgs^ e)
    {
        timer_clock->Stop();
        start_stop_b->Text = "Start";
        start_stop_b->BackColor = System::Drawing::Color::DarkGreen;
        start_stop_b->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(250)),
            static_cast<System::Int32>(static_cast<System::Byte>(0)));
        time_label->Text = "00:00:00";
        seconds = 0;
        minutes = 0;
        hours = 0;
        time = "";
    }

    void Clock::start_stop_b_Click(System::Object^ sender, System::EventArgs^ e)
    {
        if (start_stop_b->Text == "Start")
        {
            start_stop_b->Text = "Stop";
            start_stop_b->BackColor = System::Drawing::Color::DarkRed;
            start_stop_b->ForeColor = System::Drawing::Color::Red;
            timer_clock->Start();
        }
        else if (start_stop_b->Text == "Stop")
        {
            start_stop_b->Text = "Start";
            start_stop_b->BackColor = System::Drawing::Color::DarkGreen;
            start_stop_b->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(250)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            timer_clock->Stop();
        }
    }

    void Clock::timer_clock_Tick(System::Object^ sender, System::EventArgs^ e)
    {
        ms++;
        if (ms >= 100)
        {
            ms = 0;
            seconds++;
        }
        if (seconds >= 60)
        {
            seconds = 0;
            minutes++;
        }
        if (minutes >= 60)
        {
            minutes = 0;
            hours++;
        }

        if (hours < 1)
        {
            time = String::Format("{0:D2}:{1:D2}:{2:D2}", minutes, seconds, ms);
        }
        else
        {
            time = String::Format("{0:D2}:{1:D2}:{2:D2}:{3:D2}", hours, minutes, seconds, ms);
        }

        time_label->Text = time;
    }

    void Clock::Clock_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
    {
        draging = true;
        offset.X = e->X;
        offset.Y = e->Y;
    }

    void Clock::Clock_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
    {
        if (draging)
        {
            Point current_location = PointToScreen(Point(e->X, e->Y));
            Location = Point(current_location.X - offset.X, current_location.Y - offset.Y);
        }
    }

    void Clock::Clock_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
    {
        draging = false;
    }

}