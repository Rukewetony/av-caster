/*\
|*|  Copyright 2015 bill-auger <https://github.com/bill-auger/av-caster/issues>
|*|
|*|  This file is part of the AvCaster program.
|*|
|*|  AvCaster is free software: you can redistribute it and/or modify
|*|  it under the terms of the GNU Lesser General Public License version 3
|*|  as published by the Free Software Foundation.
|*|
|*|  AvCaster is distributed in the hope that it will be useful,
|*|  but WITHOUT ANY WARRANTY; without even the implied warranty of
|*|  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
|*|  GNU Lesser General Public License for more details.
|*|
|*|  You should have received a copy of the GNU Lesser General Public License
|*|  along with AvCaster.  If not, see <http://www.gnu.org/licenses/>.
\*/

#ifndef CONTROLS_H_INCLUDED
#define CONTROLS_H_INCLUDED

//[Headers]     -- You can add your own extra header files here --

#include "JuceHeader.h"

//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
  Controls is the media selection and preview GUI for the AvCaster application.
  It serves only as a consistent backdrop and/or interstitial.
                                                                    //[/Comments]
*/
class Controls  : public Component,
                  public ButtonListener,
                  public ComboBoxListener
{
public:
    //==============================================================================
    Controls ();
    ~Controls();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void buttonClicked (Button* buttonThatWasClicked);
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged);

    // Binary resources:
    static const char* preferencessystem_png;
    static const int preferencessystem_pngSize;
    static const char* confighover_png;
    static const int confighover_pngSize;
    static const char* configpushed_png;
    static const int configpushed_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.

  void broughtToFront() override ;

  void configureCombobox  (ComboBox* a_combobox) ;
  void handleSaveButton   () ;
  void handleNewButton    () ;
  void handleDeleteButton () ;
  void handlePresetCombo  () ;
  void toggleControls     () ;
  void loadConfig         () ;
  bool rejectPresetChange () ;
  void setCreatePresetMode(bool is_pending_new_preset_name) ;
  bool isCreatePresetMode () ;

    //[/UserVariables]

    //==============================================================================
    ScopedPointer<GroupComponent> controlsGroup;
    ScopedPointer<ToggleButton> screencapToggle;
    ScopedPointer<ToggleButton> cameraToggle;
    ScopedPointer<ToggleButton> textToggle;
    ScopedPointer<ToggleButton> interstitialToggle;
    ScopedPointer<ToggleButton> previewToggle;
    ScopedPointer<ToggleButton> outputToggle;
    ScopedPointer<ComboBox> presetCombo;
    ScopedPointer<ImageButton> configButton;
    ScopedPointer<TextButton> saveButton;
    ScopedPointer<TextButton> newButton;
    ScopedPointer<TextButton> deleteButton;
    ScopedPointer<Label> presetLabel;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Controls)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif // CONTROLS_H_INCLUDED
