//
// Created by Antoine Pronnier on 04/01/2025.
//

#include <iostream>

#include "funixproductions_core/core.h"
#include "./services/FunixBotUserExperienceService.h"

void testGetAll() {
    std::cout << "Test get all" << std::endl;

    funixproductions_core::FunixBotUserExperienceService service;

    funixproductions_core::PageDTO<funixproductions_core::FunixBotUserExperienceDTO> page = service.findAll();

    std::cout << "Total pages: " << page.getTotalPages() << std::endl;
    std::cout << "Actual page: " << page.getActualPage() << std::endl;
    std::cout << "Total elements database: " << page.getTotalElementsDatabase() << std::endl;
    std::cout << "Total elements this page: " << page.getTotalElementsThisPage() << std::endl;

    std::cout << "Content of the first object: " << std::endl;
    funixproductions_core::FunixBotUserExperienceDTO firstObject = page.getContent().front();

    std::cout << "Twitch user id: " << firstObject.getTwitchUserId() << std::endl;
    std::cout << "Twitch username: " << firstObject.getTwitchUsername() << std::endl;
    std::cout << "XP: " << firstObject.getXp() << std::endl;
    std::cout << "XP next level: " << firstObject.getXpNextLevel() << std::endl;
    std::cout << "Level: " << firstObject.getLevel() << std::endl;
    std::cout << "Last message date seconds: " << firstObject.getLastMessageDateSeconds() << std::endl;

    std::cout << "createdAt: " << firstObject.convertDateToString(firstObject.getCreatedAt().value()) << std::endl;
    if (firstObject.getUpdatedAt().has_value()) {
        std::cout << "updatedAt: " << firstObject.convertDateToString(firstObject.getUpdatedAt().value())
                  << std::endl;
    }
    std::cout << "id: " << firstObject.getId().value() << std::endl;
    std::cout << "----------------------" << std::endl;
}

void testFindById() {
    std::cout << "Test find by id" << std::endl;
    funixproductions_core::FunixBotUserExperienceService service;

    funixproductions_core::FunixBotUserExperienceDTO dto = service.findById("2ecd69bd-cb39-4928-81f9-f8d6ab841a03");

    std::cout << "Twitch user id: " << dto.getTwitchUserId() << std::endl;
    std::cout << "Twitch username: " << dto.getTwitchUsername() << std::endl;
    std::cout << "XP: " << dto.getXp() << std::endl;
    std::cout << "XP next level: " << dto.getXpNextLevel() << std::endl;
    std::cout << "Level: " << dto.getLevel() << std::endl;
    std::cout << "Last message date seconds: " << dto.getLastMessageDateSeconds() << std::endl;

    std::cout << "createdAt: " << dto.convertDateToString(dto.getCreatedAt().value()) << std::endl;
    if (dto.getUpdatedAt().has_value()) {
        std::cout << "updatedAt: " << dto.convertDateToString(dto.getUpdatedAt().value()) << std::endl;
    }
    std::cout << "id: " << dto.getId().value() << std::endl;

    std::cout << "----------------------" << std::endl;
}

void testFindByIdAndCheckNotFound() {
    std::cout << "Test find by id and check not found" << std::endl;
    funixproductions_core::FunixBotUserExperienceService service;

    try {
        funixproductions_core::FunixBotUserExperienceDTO dto = service.findById("2zcd69bd-cb39-4918-81f9-f8d6ab841a04");
    } catch (funixproductions_core::ApiNotFoundException &e) {
        std::cout << "Not found" << std::endl;
    }

    std::cout << "----------------------" << std::endl;
}

void testCreateData() {
    std::cout << "Test create data" << std::endl;
    funixproductions_core::FunixBotUserExperienceService service;

    funixproductions_core::FunixBotUserExperienceDTO dto;

    try {
        funixproductions_core::FunixBotUserExperienceDTO createdDto = service.create(dto);
    } catch (funixproductions_core::ApiUnauthorizedException &e) {
        std::cout << "401 Unauth, ignore because we just want to test the send object " << std::endl;
    }

    std::cout << "----------------------" << std::endl;
}

void testCreateMultipleObjectsInOneRequest() {
    std::cout << "Test create multiple objects in one request" << std::endl;
    funixproductions_core::FunixBotUserExperienceService service;

    funixproductions_core::FunixBotUserExperienceDTO dto1;
    funixproductions_core::FunixBotUserExperienceDTO dto2;

    try {
        funixproductions_core::FunixBotUserExperienceDTO createdDto = service.create({dto1, dto2});
    } catch (funixproductions_core::ApiUnauthorizedException &e) {
        std::cout << "401 Unauth, ignore because we just want to test the send object " << std::endl;
    }

    std::cout << "----------------------" << std::endl;
}

int main() {
    try {
        testGetAll();
        testFindById();
        testFindByIdAndCheckNotFound();
        testCreateData();
        testCreateMultipleObjectsInOneRequest();

        return 0;
    } catch (funixproductions_core::ApiUnauthorizedException &e) {
        std::cerr << "401 Unauth: " << e.what() << std::endl;
        return 2;
    } catch (funixproductions_core::ApiException &e) {
        std::cerr << "ApiException: " << e.what() << std::endl;
        return 1;
    }
}
