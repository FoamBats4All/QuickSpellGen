#ifndef QUICKSPELLGENERATOR_H
#define QUICKSPELLGENERATOR_H

#include <QtGui/QMainWindow>
#include "ui_quickspellgenerator.h"

class QuickSpellGenerator : public QMainWindow
{
	Q_OBJECT

public:
	QuickSpellGenerator(QWidget *parent = 0, Qt::WFlags flags = 0);
	~QuickSpellGenerator();

	enum ColumnWidths {
		ColWidth_ID = 4,
		ColWidth_Label = 47,
		ColWidth_Name = 8,
		ColWidth_IconResRef = 28,
		ColWidth_School = 6,
		ColWidth_Range = 5,
		ColWidth_VS = 4,
		ColWidth_MetaMagic = 9,
		ColWidth_TargetType = 10,
		ColWidth_ImpactScript = 31,
		ColWidth_Bard = 4,
		ColWidth_Cleric = 6,
		ColWidth_Druid = 5,
		ColWidth_Paladin = 7,
		ColWidth_Ranger = 6,
		ColWidth_Wiz_Sorc = 8,
		ColWidth_Warlock = 7,
		ColWidth_Innate = 6,
		ColWidth_ConjTime = 8,
		ColWidth_ConjAnim = 9,
		ColWidth_ConjVisual0 = 32,
		ColWidth_LowConjVisual0 = 25,
		ColWidth_ConjVisual1 = 15,
		ColWidth_ConjVisual2 = 15,
		ColWidth_ConjSoundVFX = 16,
		ColWidth_ConjSoundMale = 20,
		ColWidth_ConjSoundFemale = 20,
		ColWidth_ConjSoundOverride = 17,
		ColWidth_CastAnim = 9,
		ColWidth_CastTime = 8,
		ColWidth_CastVisual0 = 30,
		ColWidth_LowCastVisual0 = 30,
		ColWidth_CastVisual1 = 11,
		ColWidth_CastVisual2 = 11,
		ColWidth_CastSound = 13,
		ColWidth_Proj = 4,
		ColWidth_ProjModel = 14,
		ColWidth_ProjSEF = 27,
		ColWidth_LowProjSEF = 27,
		ColWidth_ProjType = 17,
		ColWidth_ProjSpwnPoint = 13,
		ColWidth_ProjSound = 14,
		ColWidth_ProjOrientation = 15,
		ColWidth_ImpactSEF = 33,
		ColWidth_LowImpactSEF = 33,
		ColWidth_ImmunityType = 14,
		ColWidth_ItemImmunity = 12,
		ColWidth_SubRadSpell1 = 12,
		ColWidth_SubRadSpell2 = 12,
		ColWidth_SubRadSpell3 = 12,
		ColWidth_SubRadSpell4 = 12,
		ColWidth_SubRadSpell5 = 12,
		ColWidth_Category = 8,
		ColWidth_Master = 6,
		ColWidth_UserType = 8,
		ColWidth_SpellDesc = 9,
		ColWidth_UseConcentration = 16,
		ColWidth_SpontaneouslyCast = 17,
		ColWidth_SpontCastClassReq = 17,
		ColWidth_AltMessage = 10,
		ColWidth_HostileSetting = 14,
		ColWidth_FeatID = 9,
		ColWidth_Counter1 = 8,
		ColWidth_Counter2 = 8,
		ColWidth_HasProjectile = 13,
		ColWidth_AsMetaMagic = 11,
		ColWidth_TargetingUI = 11,
		ColWidth_CastableOnDead = 14,
		ColWidth_REMOVED = 7
	};

	enum SchoolIndexes {
		SchoolIndex_General = 0,
		SchoolIndex_Abjuration = 1,
		SchoolIndex_Conjuration = 2,
		SchoolIndex_Divination = 3,
		SchoolIndex_Enchantment = 4,
		SchoolIndex_Evocation = 5,
		SchoolIndex_Illusion = 6,
		SchoolIndex_Necromancy = 7,
		SchoolIndex_Transmutation = 8
	};

	enum SchoolCodes {
		SchoolCode_General = 'G',
		SchoolCode_Abjuration = 'A',
		SchoolCode_Conjuration = 'C',
		SchoolCode_Divination = 'D',
		SchoolCode_Enchantment = 'E',
		SchoolCode_Evocation = 'V',
		SchoolCode_Illusion = 'I',
		SchoolCode_Necromancy = 'N',
		SchoolCode_Transmutation = 'T'
	};

	enum RangeIndexes {
		RangeIndex_Personal = 0,
		RangeIndex_Touch = 1,
		RangeIndex_Short = 2,
		RangeIndex_Medium = 3,
		RangeIndex_Long = 4,
	};

	enum RangeCodes {
		RangeCode_Personal = 'P',
		RangeCode_Touch = 'T',
		RangeCode_Short = 'S',
		RangeCode_Medium = 'M',
		RangeCode_Long = 'L',
	};

	enum MetaMagics {
		MetaMagic_Empower = 0x01,
		MetaMagic_Extend = 0x02,
		MetaMagic_Maximize = 0x04,
		MetaMagic_Quicken = 0x08,
		MetaMagic_Silent = 0x10,
		MetaMagic_Still = 0x20,
		MetaMagic_Persistent = 0x40
	};

	enum TargetTypes {
		TargetType_Self = 0x01,
		TargetType_Creatures = 0x02,
		TargetType_Area = 0x04,
		TargetType_Items = 0x08,
		TargetType_Doors = 0x10,
		TargetType_Placeables = 0x20,
		TargetType_Traps = 0x40
	};

public slots:

	void UpdateOutput();
	
	void CleanText();

	void Reset();

private:
	Ui::QuickSpellGeneratorClass ui;
};

#endif // QUICKSPELLGENERATOR_H
