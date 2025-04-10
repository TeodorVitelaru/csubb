package turism.network.rpcprotocol;

public enum ResponseType {
    OK, ERROR, NEW_REZERVARE, RECV_REZERVARI, RECV_GET_REZERVARI_BY_EXCURSIE,
    RECV_GET_EXCURSII, RECV_GET_EXCURSII_BY_DESTINATION_AND_DATE, RECV_GET_LOCURI_OCUPATE,
    USER_LOGGED_IN, USER_LOGGED_OUT,
    NEW_CLIENT, RECV_GET_CLIENT_BY_NAME_AND_PHONE;
}
