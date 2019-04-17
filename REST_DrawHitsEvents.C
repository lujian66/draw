#include "TRestTask.h"
#include "TRestG4Metadata.h"
#include "TRestG4Event.h"
#include "TRestHitsEvent.h"
#include "TRestLinearTrackEvent.h"
#include "TRestSignalEvent.h"
#include "TRestRawSignalEvent.h"
#include "TRestTrackEvent.h"
#include "TCanvas.h"

#ifndef RESTTask_PrintEvents
#define RESTTask_PrintEvents

//REST_ReadHitsEvents
Int_t REST_HitsEvent(TString fName, Int_t firstEvent = 1)
{
	TRestRun *run = new TRestRun();

	run->OpenInputFile(fName);

	run->PrintInfo();


	TRestHitsEvent *evt = new TRestHitsEvent();

	run->SetInputEvent(evt);

	//cout<<gDirectory->pwd();
	char name[10], title[20],pic_name[20];
	TCanvas *c1;
	//evt->PrintEvent();
	for (int i = 0; i < run->GetEntries(); i++){
		sprintf(name,"h%d",i);
        sprintf(title,"histo nr:%d",i);
        sprintf(pic_name,"Nevent%d.pdf",i);
			/* code */
		run->GetEntry(i);
		c1 = new TCanvas(name,title,10,10,700,500);
		//c1->Divide(3,3);
	

		evt->DrawEvent( );

		c1->Print(pic_name);
		//delete ;

	}

#ifdef REST_MANAGER
	run->GetChar("Running...\nPress a key to exit");
#endif

	return 0;
}


Int_t REST_LinearTrackEvent(TString fName, Int_t firstEvent = 0)
{
	TRestRun *run = new TRestRun();

	run->OpenInputFile(fName);

	run->PrintInfo();

	TRestLinearTrackEvent *evt = new TRestLinearTrackEvent();

	run->SetInputEvent(evt);

	run->GetEntry(firstEvent);

	evt->PrintEvent();

	delete run;

	return 0;
}

Int_t REST_RawSignalEvent(TString fName, Int_t firstEvent = 0)
{
	TRestRun *run = new TRestRun();

	run->OpenInputFile(fName);

	run->PrintInfo();

	TRestRawSignalEvent *evt = new TRestRawSignalEvent();

	run->SetInputEvent(evt);

	run->GetEntry(firstEvent);

	evt->PrintEvent();

	delete run;

	return 0;
}

Int_t REST_SignalEvent(TString fName, Int_t firstEvent = 0)
{
	TRestRun *run = new TRestRun();

	run->OpenInputFile(fName);

	run->PrintInfo();

	TRestSignalEvent *evt = new TRestSignalEvent();

	run->SetInputEvent(evt);

	run->GetEntry(firstEvent);

	evt->PrintEvent();

	delete run;

	return 0;
}

Int_t REST_TrackEvent(TString fName, Int_t firstEvent = 0)
{
	TRestRun *run = new TRestRun();

	run->OpenInputFile(fName);

	run->PrintInfo();

	TRestTrackEvent *evt = new TRestTrackEvent();

	run->SetInputEvent(evt);

	run->GetEntry(firstEvent);

	evt->PrintEvent();

	delete run;

	return 0;
}






#endif