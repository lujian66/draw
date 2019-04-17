#include "TRestTask.h"
#include "TRestG4Metadata.h"
#include "TRestG4Event.h"
//REST_ReadHitsEvents
Int_t REST_ReadHitsEvents( TString fName, int n1, int n2 )
{
    TRestRun *run = new TRestRun();

    string fname = fName.Data();
    if( !fileExists( fname ) ) { cout << "WARNING. Input file does not exist" << endl; exit(1); }
    else run->OpenInputFile( fName );

    run->OpenInputFile( fName );

    run->PrintInfo();
    int total_Event = run->GetEntries();
    cout<<"total_Event is "<<total_Event<<endl;
    /////////////////////////////

    /////////////////////////////
    // Reading events

    cout<<"hello REST_ReadhitsEvents"<<endl;
    TRestG4Event *ev = new TRestG4Event();

    run->SetInputEvent( ev );
    double x,y,z ,total_energy; 
    for(int i=0; i<total_Event;i++)
    {
            run->GetEntry ( i );
          //TVector3 pos1 =  ev->GetPrimaryEventOrigin();
          //x = pos1.X() ;
          //y = pos1.Y() ;
          //z = pos1.Z() ;
          //cout << "Source origin : (" << x << "," << y << "," << z << ") mm" << endl;

          //int ntracks = ev -> GetNumberOfTracks();
         // TVector3 pos = ev->GetTrack(1)->GetTrackOrigin();
         // TRestG4Hits *g4hits = ev->GetTrack(1) -> GetHits();
          //ev->GetTrack(1) -> PrintTrack();
         // double first_3mm_dep = 0 ;
        // ev->PrintEvent();
            
        // TRestG4Event *ev = new TRestG4Event();
         ev->PrintEvent();
         
         TRestG4Hits *g4hits =NULL;
         TVector3 initEdepPos =  ev->GetTrack(0)->GetTrackOrigin();
         double first_3mm_Edep=0;
         for (int tra = 0; tra < ev -> GetNumberOfTracks(); tra++){
             g4hits = ev->GetTrack(tra)->GetHits( );
           for (int h = 0; h < g4hits->GetNumberOfHits() ; h++){
                TVector3 Hitpos = g4hits->GetPosition ( h );
                TVector3 V=initEdepPos-Hitpos;
                if ( V.Mag2() < 3){
                  first_3mm_Edep=first_3mm_Edep+ g4hits->GetEnergy( h ); 
                }
           }
        }
        cout<< "first_3mm_Edep " <<first_3mm_Edep<<endl;
        
        

    }

    delete ev;


    /////////////////////////////

    delete run;

    return 0;
}
