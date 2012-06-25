#include "stdafx.h"
#include "quickspellgenerator.h"

QuickSpellGenerator::QuickSpellGenerator(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
}

QuickSpellGenerator::~QuickSpellGenerator()
{

}

void QuickSpellGenerator::UpdateOutput() {
	// Clear current ouput.
	ui.Output->clear();
	uint number = 0;
	QString content;

	// ID
	ui.Output->insert( ui.ID->text().leftJustified( ColWidth_ID + 1, ' ' ) );

	// Label
	ui.Output->insert( ui.Label->text().replace( " ", "_" ).leftJustified( ColWidth_Label + 1, ' ' ) );

	// Name
	ui.Output->insert( ui.Name->text().leftJustified( ColWidth_Name + 1, ' ' ) );

	// IconResRef
	ui.Output->insert( ui.IconResRef->text().leftJustified( ColWidth_IconResRef + 1, ' ' ) );

	// School
	switch ( ui.School->currentIndex() ) {
		case SchoolIndex_General: content = SchoolCode_General; break;
		case SchoolIndex_Abjuration: content = SchoolCode_Abjuration; break;
		case SchoolIndex_Conjuration: content = SchoolCode_Conjuration; break;
		case SchoolIndex_Divination: content = SchoolCode_Divination; break;
		case SchoolIndex_Enchantment: content = SchoolCode_Enchantment; break;
		case SchoolIndex_Evocation: content = SchoolCode_Evocation; break;
		case SchoolIndex_Illusion: content = SchoolCode_Illusion; break;
		case SchoolIndex_Necromancy: content = SchoolCode_Necromancy; break;
		case SchoolIndex_Transmutation: content = SchoolCode_Transmutation; break;
	}
	ui.Output->insert( content.leftJustified( ColWidth_School + 1, ' ' ) );

	// Range
	switch ( ui.Range->currentIndex() ) {
		case RangeIndex_Personal: content = RangeCode_Personal; break;
		case RangeIndex_Touch: content = RangeCode_Touch; break;
		case RangeIndex_Short: content = RangeCode_Short; break;
		case RangeIndex_Medium: content = RangeCode_Medium; break;
		case RangeIndex_Long: content = RangeCode_Long; break;
	}
	ui.Output->insert( content.leftJustified( ColWidth_Range + 1, ' ' ) );

	// VS
	content = "";
	if ( ui.VS_V->isChecked() ) content += "v";
	if ( ui.VS_S->isChecked() ) content += "s";
	if ( content.isEmpty() ) content = "****";
	ui.Output->insert( content.leftJustified( ColWidth_VS + 1, ' ' ) );

	// MetaMagic
	number = 0;
	if ( ui.MetaMagic_Empower->isChecked() ) number += MetaMagic_Empower;
	if ( ui.MetaMagic_Extend->isChecked() ) number += MetaMagic_Extend;
	if ( ui.MetaMagic_Maximize->isChecked() ) number += MetaMagic_Maximize;
	if ( ui.MetaMagic_Quicken->isChecked() ) number += MetaMagic_Quicken;
	if ( ui.MetaMagic_Silent->isChecked() ) number += MetaMagic_Silent;
	if ( ui.MetaMagic_Still->isChecked() ) number += MetaMagic_Still;
	if ( ui.MetaMagic_Persistent->isChecked() ) number += MetaMagic_Persistent;
	ui.Output->insert( QString().setNum( number, 16 ).rightJustified( 2, '0' ).prepend( "0x" ).leftJustified( ColWidth_MetaMagic + 1, ' ' ) );

	// TargetType
	number = 0;
	if ( ui.TargetType_Self->isChecked() ) number += TargetType_Self;
	if ( ui.TargetType_Creatures->isChecked() ) number += TargetType_Creatures;
	if ( ui.TargetType_Area->isChecked() ) number += TargetType_Area;
	if ( ui.TargetType_Items->isChecked() ) number += TargetType_Items;
	if ( ui.TargetType_Doors->isChecked() ) number += TargetType_Doors;
	if ( ui.TargetType_Placeables->isChecked() ) number += TargetType_Placeables;
	if ( ui.TargetType_Traps->isChecked() ) number += TargetType_Traps;
	ui.Output->insert( QString().setNum( number, 16 ).rightJustified( 2, '0' ).prepend( "0x" ).leftJustified( ColWidth_TargetType + 1, ' ' ) );

	// ImpactScript
	ui.Output->insert( ui.ImpactScript->text().replace( " ", "_" ).leftJustified( ColWidth_ImpactScript + 1, ' ' ) );

	// Bard
	content = QString().setNum( ui.Bard->value(), 10 );
	if ( ui.Bard->value() < 0 ) content = "****";
	ui.Output->insert( content.leftJustified( ColWidth_Bard + 1, ' ' ) );

	// Cleric
	content = QString().setNum( ui.Cleric->value(), 10 );
	if ( ui.Cleric->value() < 0 ) content = "****";
	ui.Output->insert( content.leftJustified( ColWidth_Cleric + 1, ' ' ) );

	// Druid
	content = QString().setNum( ui.Druid->value(), 10 );
	if ( ui.Druid->value() < 0 ) content = "****";
	ui.Output->insert( content.leftJustified( ColWidth_Druid + 1, ' ' ) );

	// Paladin
	content = QString().setNum( ui.Paladin->value(), 10 );
	if ( ui.Paladin->value() < 1 ) content = "****";
	ui.Output->insert( content.leftJustified( ColWidth_Paladin + 1, ' ' ) );

	// Ranger
	content = QString().setNum( ui.Ranger->value(), 10 );
	if ( ui.Ranger->value() < 1 ) content = "****";
	ui.Output->insert( content.leftJustified( ColWidth_Ranger + 1, ' ' ) );

	// Wiz_Sorc
	content = QString().setNum( ui.Wiz_Sorc->value(), 10 );
	if ( ui.Wiz_Sorc->value() < 0 ) content = "****";
	ui.Output->insert( content.leftJustified( ColWidth_Wiz_Sorc + 1, ' ' ) );

	// Warlock
	content = QString().setNum( ui.Warlock->value(), 10 );
	if ( ui.Warlock->value() < 1 ) content = "****";
	ui.Output->insert( content.leftJustified( ColWidth_Warlock + 1, ' ' ) );

	// Innate
	content = QString().setNum( ui.Innate->value(), 10 );
	if ( ui.Innate->value() < 0 ) content = "****";
	ui.Output->insert( content.leftJustified( ColWidth_Innate + 1, ' ' ) );

	// ConjTime
	ui.Output->insert( QString().setNum( ui.ConjTime->value(), 10 ).leftJustified( ColWidth_ConjTime + 1, ' ' ) );

	// ConjAnim
	content = ui.ConjAnim->currentText();
	if ( ui.ConjAnim->currentIndex() == 0 ) content = "****";
	ui.Output->insert( content.leftJustified( ColWidth_ConjAnim + 1, ' ' ) );

	// ConjVisual0
	content = ui.ConjVisual0->currentText();
	if ( ui.ConjVisual0->currentIndex() == 0 ) content = "****";
	ui.Output->insert( content.leftJustified( ColWidth_ConjVisual0 + 1, ' ' ) );

	// LowConjVisual0
	content = ui.LowConjVisual0->currentText();
	if ( ui.LowConjVisual0->currentIndex() == 0 ) content = "****";
	ui.Output->insert( content.leftJustified( ColWidth_LowConjVisual0 + 1, ' ' ) );

	// ConjVisual1
	content = ui.ConjVisual1->currentText();
	if ( ui.ConjVisual1->currentIndex() == 0 ) content = "****";
	ui.Output->insert( content.leftJustified( ColWidth_ConjVisual1 + 1, ' ' ) );

	// ConjVisual2
	content = ui.ConjVisual2->currentText();
	if ( ui.ConjVisual2->currentIndex() == 0 ) content = "****";
	ui.Output->insert( content.leftJustified( ColWidth_ConjVisual2 + 1, ' ' ) );

	// ConjSoundVFX
	content = ui.ConjSoundVFX->currentText();
	if ( ui.ConjSoundVFX->currentIndex() == 0 ) content = "****";
	ui.Output->insert( content.leftJustified( ColWidth_ConjSoundVFX + 1, ' ' ) );

	// ConjSoundMale
	content = ui.ConjSoundMale->currentText();
	if ( ui.ConjSoundMale->currentIndex() == 0 ) content = "****";
	ui.Output->insert( content.leftJustified( ColWidth_ConjSoundMale + 1, ' ' ) );

	// ConjSoundFemale
	content = ui.ConjSoundFemale->currentText();
	if ( ui.ConjSoundFemale->currentIndex() == 0 ) content = "****";
	ui.Output->insert( content.leftJustified( ColWidth_ConjSoundFemale + 1, ' ' ) );

	// ConjSoundOverride
	content = ui.ConjSoundOverride->currentText();
	if ( ui.ConjSoundOverride->currentIndex() == 0 ) content = "****";
	ui.Output->insert( content.leftJustified( ColWidth_ConjSoundOverride + 1, ' ' ) );

	// CastAnim
	content = ui.CastAnim->currentText();
	if ( ui.CastAnim->currentIndex() == 0 ) content = "****";
	ui.Output->insert( content.leftJustified( ColWidth_CastAnim + 1, ' ' ) );

	// CastTime
	ui.Output->insert( QString().setNum( ui.CastTime->value(), 10 ).leftJustified( ColWidth_CastTime + 1, ' ' ) );

	// CastVisual0
	content = ui.CastVisual0->currentText();
	if ( ui.CastVisual0->currentIndex() == 0 ) content = "****";
	ui.Output->insert( content.leftJustified( ColWidth_CastVisual0 + 1, ' ' ) );

	// LowCastVisual0
	content = ui.LowCastVisual0->currentText();
	if ( ui.LowCastVisual0->currentIndex() == 0 ) content = "****";
	ui.Output->insert( content.leftJustified( ColWidth_LowCastVisual0 + 1, ' ' ) );

	// CastVisual1
	ui.Output->insert( QString( "****" ).leftJustified( ColWidth_CastVisual1 + 1, ' ' ) );

	// CastVisual2
	ui.Output->insert( QString( "****" ).leftJustified( ColWidth_CastVisual2 + 1, ' ' ) );

	// CastSound
	ui.Output->insert( QString( "****" ).leftJustified( ColWidth_CastSound + 1, ' ' ) );

	// Proj
	content = "0";
	if ( ui.Proj->isChecked() ) content = "1";
	ui.Output->insert( content.leftJustified( ColWidth_Proj + 1, ' ' ) );

	// ProjModel
	content = ui.ProjModel->currentText();
	if ( ui.ProjModel->currentIndex() == 0 ) content = "****";
	ui.Output->insert( content.leftJustified( ColWidth_ProjModel + 1, ' ' ) );

	// ProjSEF
	content = ui.ProjSEF->currentText();
	if ( ui.ProjSEF->currentIndex() == 0 ) content = "****";
	ui.Output->insert( content.leftJustified( ColWidth_ProjSEF + 1, ' ' ) );

	// LowProjSEF
	content = ui.LowProjSEF->currentText();
	if ( ui.LowProjSEF->currentIndex() == 0 ) content = "****";
	ui.Output->insert( content.leftJustified( ColWidth_LowProjSEF + 1, ' ' ) );

	// ProjType
	content = ui.ProjType->currentText();
	if ( ui.ProjType->currentIndex() == 0 ) content = "****";
	ui.Output->insert( content.leftJustified( ColWidth_ProjType + 1, ' ' ) );

	// ProjSpwnPoint
	content = ui.ProjSpwnPoint->currentText();
	if ( ui.ProjSpwnPoint->currentIndex() == 0 ) content = "****";
	ui.Output->insert( content.leftJustified( ColWidth_ProjSpwnPoint + 1, ' ' ) );

	// ProjSound
	content = ui.ProjSound->currentText();
	if ( ui.ProjSound->currentIndex() == 0 ) content = "****";
	ui.Output->insert( content.leftJustified( ColWidth_ProjSound + 1, ' ' ) );

	// ProjOrientation
	content = ui.ProjOrientation->currentText();
	if ( ui.ProjOrientation->currentIndex() == 0 ) content = "****";
	ui.Output->insert( content.leftJustified( ColWidth_ProjOrientation + 1, ' ' ) );

	// ImpactSEF
	content = ui.ImpactSEF->currentText();
	if ( ui.ImpactSEF->currentIndex() == 0 ) content = "****";
	ui.Output->insert( content.leftJustified( ColWidth_ImpactSEF + 1, ' ' ) );

	// LowImpactSEF
	content = ui.LowImpactSEF->currentText();
	if ( ui.LowImpactSEF->currentIndex() == 0 ) content = "****";
	ui.Output->insert( content.leftJustified( ColWidth_LowImpactSEF + 1, ' ' ) );

	// ImmunityType
	ui.Output->insert( QString( "****" ).leftJustified( ColWidth_ImmunityType + 1, ' ' ) );

	// ItemImmunity
	content = "0";
	if ( ui.ItemImmunity->isChecked() ) content = "1";
	ui.Output->insert( content.leftJustified( ColWidth_ItemImmunity + 1, ' ' ) );

	// SubRadSpell1 ... SubRadSpell5
	if ( ui.SubRadSpell1->value() >= 0 ) ui.Output->insert( ui.SubRadSpell1->text().leftJustified( ColWidth_SubRadSpell1 + 1, ' ' ) );
	else ui.Output->insert( QString( "****" ).leftJustified( ColWidth_SubRadSpell1 + 1, ' ' ) );
	if ( ui.SubRadSpell2->value() >= 0 ) ui.Output->insert( ui.SubRadSpell2->text().leftJustified( ColWidth_SubRadSpell2 + 1, ' ' ) );
	else ui.Output->insert( QString( "****" ).leftJustified( ColWidth_SubRadSpell2 + 1, ' ' ) );
	if ( ui.SubRadSpell3->value() >= 0 ) ui.Output->insert( ui.SubRadSpell3->text().leftJustified( ColWidth_SubRadSpell3 + 1, ' ' ) );
	else ui.Output->insert( QString( "****" ).leftJustified( ColWidth_SubRadSpell3 + 1, ' ' ) );
	if ( ui.SubRadSpell4->value() >= 0 ) ui.Output->insert( ui.SubRadSpell4->text().leftJustified( ColWidth_SubRadSpell4 + 1, ' ' ) );
	else ui.Output->insert( QString( "****" ).leftJustified( ColWidth_SubRadSpell4 + 1, ' ' ) );
	if ( ui.SubRadSpell5->value() >= 0 ) ui.Output->insert( ui.SubRadSpell5->text().leftJustified( ColWidth_SubRadSpell5 + 1, ' ' ) );
	else ui.Output->insert( QString( "****" ).leftJustified( ColWidth_SubRadSpell5 + 1, ' ' ) );

	// Category
	ui.Output->insert( ui.Category->text().leftJustified( ColWidth_Category + 1, ' ' ) );

	// Master
	if ( ui.Master->value() >= 0 ) ui.Output->insert( ui.Master->text().leftJustified( ColWidth_Master + 1, ' ' ) );
	else ui.Output->insert( QString( "****" ).leftJustified( ColWidth_Master + 1, ' ' ) );

	// UserType
	ui.Output->insert( QString().number( ui.UserType->currentIndex() + 1, 10 ).leftJustified( ColWidth_UserType + 1, ' ' ) );

	// SpellDesc
	ui.Output->insert( ui.SpellDesc->text().leftJustified( ColWidth_SpellDesc + 1, ' ' ) );

	// UseConcentration
	content = "0";
	if ( ui.UseConcentration->isChecked() ) content = "1";
	ui.Output->insert( content.leftJustified( ColWidth_UseConcentration + 1, ' ' ) );

	// SpontaneouslyCast
	content = "0";
	if ( ui.SpontaneouslyCast->isChecked() ) content = "1";
	ui.Output->insert( content.leftJustified( ColWidth_SpontaneouslyCast + 1, ' ' ) );

	// SpontCastClassReq
	content = ui.SpontCastClassReq->text();
	if ( !ui.SpontaneouslyCast->isChecked() || ui.SpontCastClassReq->value() < 0 ) content = "****";
	ui.Output->insert( content.leftJustified( ColWidth_SpontCastClassReq + 1, ' ' ) );

	// AltMessage
	if ( ui.AltMessage->value() >= 0 ) ui.Output->insert( ui.AltMessage->text().leftJustified( ColWidth_AltMessage + 1, ' ' ) );
	else ui.Output->insert( QString( "****" ).leftJustified( ColWidth_AltMessage + 1, ' ' ) );

	// HostileSetting
	content = "****";
	if ( ui.HostileSetting->isChecked() ) content = "1";
	ui.Output->insert( content.leftJustified( ColWidth_HostileSetting + 1, ' ' ) );

	// FeatID
	if ( ui.FeatID->value() >= 0 ) ui.Output->insert( ui.FeatID->text().leftJustified( ColWidth_FeatID + 1, ' ' ) );
	else ui.Output->insert( QString( "****" ).leftJustified( ColWidth_FeatID + 1, ' ' ) );

	// So two marines walk into a bar and say, "... where's the counter?"
	ui.Output->insert( QString( "****" ).leftJustified( ColWidth_Counter1 + 1, ' ' ) );
	ui.Output->insert( QString( "****" ).leftJustified( ColWidth_Counter2 + 1, ' ' ) );

	// HasProjectile
	content = "0";
	if ( ui.HasProjectile->isChecked() ) content = "1";
	ui.Output->insert( content.leftJustified( ColWidth_HasProjectile + 1, ' ' ) );

	// AsMetaMagic
	ui.Output->insert( QString( "****" ).leftJustified( ColWidth_AsMetaMagic + 1, ' ' ) );

	// TargetingUI
	number = 0;
	switch ( ui.TargetingUI->currentIndex() ) {
		case 0: number = 0; break;
		case 1: number = 14; break;
		case 2: number = 12; break;
		case 3: number = 6; break;
		case 4: number = 7; break;
		case 5: number = 8; break;
		case 6: number = 2; break;
		case 7: number = 9; break;
		case 8: number = 10; break;
		case 9: number = 18; break;
		case 10: number = 17; break;
		case 11: number = 19; break;
		case 12: number = 15; break;
		case 13: number = 13; break;
		case 14: number = 16; break;
		case 15: number = 4; break;
		case 16: number = 3; break;
		case 17: number = 5; break;
		case 18: number = 11; break;
		case 19: number = 1; break;
	}
	ui.Output->insert( QString().number( number, 10 ).leftJustified( ColWidth_TargetingUI + 1, ' ' ) );

	// CastableOnDead
	content = "0";
	if ( ui.CastableOnDead->isChecked() ) content = "1";
	ui.Output->insert( content.leftJustified( ColWidth_CastableOnDead + 1, ' ' ) );

	// REMOVED
	ui.Output->insert( QString( "0" ).leftJustified( ColWidth_REMOVED + 1, ' ' ) );

}
	
void QuickSpellGenerator::CleanText() {
	QString text = ui.SpellText->document()->toHtml();
	text = text.replace( "\t", "" ).replace( QString().fromWCharArray( L"’" ), "'" ).replace( QString().fromWCharArray( L"“" ), "\"" ).replace( QString().fromWCharArray( L"”" ), "\"" ).replace( QString().fromWCharArray( L"—" ), " -- " );
	ui.SpellText->document()->setHtml( text );
}

void QuickSpellGenerator::Reset() {

}