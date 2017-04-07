#pragma once
#include "Finch\Finch.h"

namespace FinchVS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	Finch myFinch;
	//Varible to hold the speed
	int speed;
	/// <summary>
	/// Controls a Finch robot
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
		
			myFinch.connect();
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}









	private: System::Windows::Forms::RadioButton^  slowBtn;
	private: System::Windows::Forms::GroupBox^  speedGrpBx;
	private: System::Windows::Forms::RadioButton^  fastBtn;
	private: System::Windows::Forms::RadioButton^  medBtn;
	private: System::Windows::Forms::Button^  stopBtn;
	private: System::Windows::Forms::Button^  backBtn;
	private: System::Windows::Forms::Button^  forwardBtn;
	private: System::Windows::Forms::Button^  setLedBtn;
	private: System::Windows::Forms::ColorDialog^  colorDialog;
	private: System::Windows::Forms::TrackBar^  trackBar1;



	protected:

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
		void InitializeComponent(void)
		{
			this->slowBtn = (gcnew System::Windows::Forms::RadioButton());
			this->speedGrpBx = (gcnew System::Windows::Forms::GroupBox());
			this->fastBtn = (gcnew System::Windows::Forms::RadioButton());
			this->medBtn = (gcnew System::Windows::Forms::RadioButton());
			this->stopBtn = (gcnew System::Windows::Forms::Button());
			this->backBtn = (gcnew System::Windows::Forms::Button());
			this->forwardBtn = (gcnew System::Windows::Forms::Button());
			this->setLedBtn = (gcnew System::Windows::Forms::Button());
			this->colorDialog = (gcnew System::Windows::Forms::ColorDialog());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->speedGrpBx->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			this->SuspendLayout();
			// 
			// slowBtn
			// 
			this->slowBtn->AutoSize = true;
			this->slowBtn->Location = System::Drawing::Point(6, 19);
			this->slowBtn->Name = L"slowBtn";
			this->slowBtn->Size = System::Drawing::Size(48, 17);
			this->slowBtn->TabIndex = 7;
			this->slowBtn->Text = L"Slow";
			this->slowBtn->UseVisualStyleBackColor = true;
			this->slowBtn->CheckedChanged += gcnew System::EventHandler(this, &MyForm::slowBtn_CheckedChanged);
			// 
			// speedGrpBx
			// 
			this->speedGrpBx->Controls->Add(this->fastBtn);
			this->speedGrpBx->Controls->Add(this->medBtn);
			this->speedGrpBx->Controls->Add(this->slowBtn);
			this->speedGrpBx->Location = System::Drawing::Point(134, 5);
			this->speedGrpBx->Name = L"speedGrpBx";
			this->speedGrpBx->Size = System::Drawing::Size(78, 85);
			this->speedGrpBx->TabIndex = 8;
			this->speedGrpBx->TabStop = false;
			this->speedGrpBx->Text = L"Speed";
			// 
			// fastBtn
			// 
			this->fastBtn->AutoSize = true;
			this->fastBtn->Location = System::Drawing::Point(6, 65);
			this->fastBtn->Name = L"fastBtn";
			this->fastBtn->Size = System::Drawing::Size(45, 17);
			this->fastBtn->TabIndex = 9;
			this->fastBtn->Text = L"Fast";
			this->fastBtn->UseVisualStyleBackColor = true;
			this->fastBtn->CheckedChanged += gcnew System::EventHandler(this, &MyForm::fastBtn_CheckedChanged);
			// 
			// medBtn
			// 
			this->medBtn->AutoSize = true;
			this->medBtn->Location = System::Drawing::Point(6, 42);
			this->medBtn->Name = L"medBtn";
			this->medBtn->Size = System::Drawing::Size(62, 17);
			this->medBtn->TabIndex = 8;
			this->medBtn->Text = L"Medium";
			this->medBtn->UseVisualStyleBackColor = true;
			this->medBtn->CheckedChanged += gcnew System::EventHandler(this, &MyForm::medBtn_CheckedChanged);
			// 
			// stopBtn
			// 
			this->stopBtn->Location = System::Drawing::Point(12, 38);
			this->stopBtn->Name = L"stopBtn";
			this->stopBtn->Size = System::Drawing::Size(116, 23);
			this->stopBtn->TabIndex = 10;
			this->stopBtn->Text = L"Stop Motor";
			this->stopBtn->UseVisualStyleBackColor = true;
			this->stopBtn->Click += gcnew System::EventHandler(this, &MyForm::stopBtn_Click);
			// 
			// backBtn
			// 
			this->backBtn->Location = System::Drawing::Point(12, 67);
			this->backBtn->Name = L"backBtn";
			this->backBtn->Size = System::Drawing::Size(116, 23);
			this->backBtn->TabIndex = 11;
			this->backBtn->Text = L"Move Backwards";
			this->backBtn->UseVisualStyleBackColor = true;
			this->backBtn->Click += gcnew System::EventHandler(this, &MyForm::backBtn_Click);
			// 
			// forwardBtn
			// 
			this->forwardBtn->Location = System::Drawing::Point(12, 9);
			this->forwardBtn->Name = L"forwardBtn";
			this->forwardBtn->Size = System::Drawing::Size(116, 23);
			this->forwardBtn->TabIndex = 12;
			this->forwardBtn->Text = L"Move Forward";
			this->forwardBtn->UseVisualStyleBackColor = true;
			this->forwardBtn->Click += gcnew System::EventHandler(this, &MyForm::forwardBtn_Click);
			// 
			// setLedBtn
			// 
			this->setLedBtn->Location = System::Drawing::Point(12, 361);
			this->setLedBtn->Name = L"setLedBtn";
			this->setLedBtn->Size = System::Drawing::Size(104, 23);
			this->setLedBtn->TabIndex = 10;
			this->setLedBtn->Text = L"Set LED";
			this->setLedBtn->UseVisualStyleBackColor = true;
			this->setLedBtn->Click += gcnew System::EventHandler(this, &MyForm::setLedBtn_Click);
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(218, 5);
			this->trackBar1->Maximum = 256;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Orientation = System::Windows::Forms::Orientation::Vertical;
			this->trackBar1->Size = System::Drawing::Size(45, 104);
			this->trackBar1->TabIndex = 13;
			this->trackBar1->TickFrequency = 32;
			this->trackBar1->TickStyle = System::Windows::Forms::TickStyle::Both;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(569, 396);
			this->Controls->Add(this->trackBar1);
			this->Controls->Add(this->setLedBtn);
			this->Controls->Add(this->forwardBtn);
			this->Controls->Add(this->backBtn);
			this->Controls->Add(this->stopBtn);
			this->Controls->Add(this->speedGrpBx);
			this->Name = L"MyForm";
			this->Text = L"Finch Controller";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->speedGrpBx->ResumeLayout(false);
			this->speedGrpBx->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}


//Makes the Finch go forward
private: System::Void forwardBtn_Click(System::Object^  sender, System::EventArgs^  e) {
	myFinch.setMotors(speed, speed);
}
//Stops the Finch
private: System::Void stopBtn_Click(System::Object^  sender, System::EventArgs^  e) {
	myFinch.setMotors(0, 0);
}
//Makes the Finch go backwards
private: System::Void backBtn_Click(System::Object^  sender, System::EventArgs^  e) {
	speed *=-1;
	myFinch.setMotors(speed, speed);
}
//Sets the LED RGB values for the Finch nose light
private: System::Void setLedBtn_Click(System::Object^  sender, System::EventArgs^  e) {
	colorDialog->ShowDialog();
	Color pickedColor = colorDialog->Color;
	myFinch.setLED(pickedColor.R, pickedColor.G, pickedColor.B);
}
//Sets the Finch's speed value to slow
private: System::Void slowBtn_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (slowBtn->Checked)
		speed = 85;
}
//Sets the Finch's speed value to medium
private: System::Void medBtn_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (medBtn->Checked)
		speed = 128;
}
//Sets the Finch's speed value to fast
private: System::Void fastBtn_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (fastBtn->Checked)
		speed = 255;
}
private: System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
}
};
}
