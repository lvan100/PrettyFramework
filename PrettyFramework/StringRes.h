#pragma once

namespace PrettyFramework {
	
	/**
	 * Ë¢ĞÂËùÓĞ×Ö·û´®
	 */
	void RefreshStrings();

	/**
	 * ×Ö·û´®ÓïÑÔ
	 */
	enum Language {
		ChineseSimplified,
		ChineseTraditional,
	};

	/**
	 * ÉèÖÃ×Ö·û´®ÓïÑÔ
	 */
	void SetLanguage(Language lan);

	/**
	 * ¸ù¾İ×Ö·û´®ID»ñÈ¡×Ö·û´®
	 */
	CString& GetString(CString id);
	
}