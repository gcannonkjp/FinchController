#pragma once
#include "Finch\Finch.h"

namespace FinchVS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	//Class to control Finch
	Finch myFinch;
	//Global varible to hold Finch's conenction status
	int connectionStatus;
	/// <summary>
	/// Controls a Finch robot
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			
			//Conenct to Finch on startup
			connectionStatus = myFinch.connect();
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
















	private: System::Windows::Forms::Button^  setLedBtn;
	private: System::Windows::Forms::ColorDialog^  colorDialog;
	private: System::Windows::Forms::TrackBar^  speedControl;
	private: System::Windows::Forms::Label^  stopLbl;
	private: System::Windows::Forms::Label^  forwrdLbl;
	private: System::Windows::Forms::Label^  reverseLbl;




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
			this->setLedBtn = (gcnew System::Windows::Forms::Button());
			this->colorDialog = (gcnew System::Windows::Forms::ColorDialog());
			this->speedControl = (gcnew System::Windows::Forms::TrackBar());
			this->stopLbl = (gcnew System::Windows::Forms::Label());
			this->forwrdLbl = (gcnew System::Windows::Forms::Label());
			this->reverseLbl = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->speedControl))->BeginInit();
			this->SuspendLayout();
			// 
			// setLedBtn
			// 
			this->setLedBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->setLedBtn->Location = System::Drawing::Point(12, 361);
			this->setLedBtn->Name = L"setLedBtn";
			this->setLedBtn->Size = System::Drawing::Size(104, 23);
			this->setLedBtn->TabIndex = 10;
			this->setLedBtn->Text = L"Set LED";
			this->setLedBtn->UseVisualStyleBackColor = true;
			this->setLedBtn->Click += gcnew System::EventHandler(this, &MyForm::setLedBtn_Click);
			// 
			// speedControl
			// 
			this->speedControl->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->speedControl->Location = System::Drawing::Point(512, 12);
			this->speedControl->Maximum = 255;
			this->speedControl->Minimum = -255;
			this->speedControl->Name = L"speedControl";
			this->speedControl->Orientation = System::Windows::Forms::Orientation::Vertical;
			this->speedControl->Size = System::Drawing::Size(45, 372);
			this->speedControl->SmallChange = 32;
			this->speedControl->TabIndex = 13;
			this->speedControl->TickFrequency = 32;
			this->speedControl->TickStyle = System::Windows::Forms::TickStyle::Both;
			this->speedControl->Scroll += gcnew System::EventHandler(this, &MyForm::speedControl_Scroll);
			// 
			// stopLbl
			// 
			this->stopLbl->AutoSize = true;
			this->stopLbl->Location = System::Drawing::Point(459, 190);
			this->stopLbl->Name = L"stopLbl";
			this->stopLbl->Size = System::Drawing::Size(47, 13);
			this->stopLbl->TabIndex = 14;
			this->stopLbl->Text = L"Stopped";
			// 
			// forwrdLbl
			// 
			this->forwrdLbl->AutoSize = true;
			this->forwrdLbl->Location = System::Drawing::Point(413, 21);
			this->forwrdLbl->Name = L"forwrdLbl";
			this->forwrdLbl->Size = System::Drawing::Size(93, 13);
			this->forwrdLbl->TabIndex = 15;
			this->forwrdLbl->Text = L"Full speed forward";
			// 
			// reverseLbl
			// 
			this->reverseLbl->AutoSize = true;
			this->reverseLbl->Location = System::Drawing::Point(413, 361);
			this->reverseLbl->Name = L"reverseLbl";
			this->reverseLbl->Size = System::Drawing::Size(93, 13);
			this->reverseLbl->TabIndex = 16;
			this->reverseLbl->Text = L"Full speed reverse";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(569, 396);
			this->Controls->Add(this->reverseLbl);
			this->Controls->Add(this->forwrdLbl);
			this->Controls->Add(this->stopLbl);
			this->Controls->Add(this->speedControl);
			this->Controls->Add(this->setLedBtn);
			this->KeyPreview = true;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Finch Controller";
			this->Shown += gcnew System::EventHandler(this, &MyForm::MyForm_Shown);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->speedControl))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

//Sets the LED RGB values for the Finch nose light
private: System::Void setLedBtn_Click(System::Object^  sender, System::EventArgs^  e) {
	colorDialog->ShowDialog();
	Color pickedColor = colorDialog->Color;
	myFinch.setLED(pickedColor.R, pickedColor.G, pickedColor.B);
}

//If no connection to Finch then show a message
private: System::Void MyForm_Shown(System::Object^  sender, System::EventArgs^  e) {
	if (connectionStatus = -1)
		MessageBox::Show("No connection to Finch. Connect Finch and then press the Reconnect button.");

	//Auto select the speed track bar 
	if (MyForm::Focused)
		speedControl->Focus();
}
//Governs the speed control
private: System::Void speedControl_Scroll(System::Object^  sender, System::EventArgs^  e) {
	myFinch.setMotors(speedControl->Value, speedControl->Value);
}
//Keypress handler
private: System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	if (e->KeyCode==Keys::Space)
	{
		speedControl->Value = 0;
		speedControl->Refresh();
	}

}
};
}
